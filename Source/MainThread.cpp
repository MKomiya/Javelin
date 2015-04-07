#include "MainThread.h"
#include "Input.h"
#include "LuaStatement.h"
#include "LuaScene.h"
#include "Actor.h"
#include "DebugPut.h"

HWND MainThread::hWnd;
HINSTANCE MainThread::hInstance;

LPDIRECT3D9 MainThread::pD3D = NULL;
LPDIRECT3DDEVICE9 MainThread::pD3Ddevice = NULL;
IDirect3DVertexBuffer9* MainThread::pVertex = NULL;
ID3DXLine* MainThread::pLine = NULL;

Input* MainThread::pInput = NULL;

LuaStatement* MainThread::Ls = NULL;
hash_map<string, LuaScene*> MainThread::sceneMap;
list<Actor*> MainThread::actorList;
string MainThread::now_scene;
bool MainThread::it_moved = false;
list<Actor*>::iterator MainThread::it_task;

MainThread::MainThread(HWND hWnd, HINSTANCE hInstance)
{
	this->hWnd = hWnd;
	this->hInstance = hInstance;
	request_quit = false;
	lasttime = 0;

	pInput = new Input();

	Ls = new LuaStatement();
	now_scene = "nil";
}

void MainThread::Run()
{
	BeginFrame();

	ProcessFrame();
	DrawFrame();

	EndFrame();
}

void MainThread::InitDirectX()
{
	// Create Direct3D9 Object
	pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    if(pD3D == NULL)
	{
		throw "DirectXDevice�̏������Ɏ��s���܂���";
    }

	// Check DoubleStencil Support
	D3DCAPS9 Caps;
	pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &Caps);
	if( !(Caps.StencilCaps & D3DSTENCILCAPS_TWOSIDED) )
	{
		MessageBox(0,"�_�u���X�e���V���ɑΉ����Ă��܂���B","",MB_OK);
	}

	// Get Display Mode
    D3DDISPLAYMODE d3ddm;
    if(FAILED(pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
    {
		throw "DirectX3DDevice�̏������Ɏ��s���܂���";
    }

	// Create Direct3D Device Object
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
    d3dpp.PresentationInterval  = D3DPRESENT_INTERVAL_IMMEDIATE;
	d3dpp.EnableAutoDepthStencil = TRUE;
	// Zbuffer24bit and Stencilbuffer8bit
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	// Enable DoubleStencil
	d3dpp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;

    if(FAILED(pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_FPU_PRESERVE,
        &d3dpp,&pD3Ddevice)))
    {
		//DXTRACE_MSG(_T("3DDeviceObject�̃\�t�g�E�F�A���[�h�������Ɏ��s���܂���"));
    }

    // �e�N�X�`���̃u�����f�B���O���@���`����
    pD3Ddevice->SetTextureStageState( 0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
    pD3Ddevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
    pD3Ddevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	// Enable Alpha Blend
    pD3Ddevice->SetRenderState( D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA );
    pD3Ddevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
    pD3Ddevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );

	if(FAILED(pD3Ddevice->CreateVertexBuffer( sizeof(CUSTOMVERTEX)*4, D3DUSAGE_WRITEONLY, FVF_CUSTOM, D3DPOOL_MANAGED, &pVertex, NULL) ))
	{
		throw "VertexBuffer�̍쐬�Ɏ��s���܂����B";
	}

	// Create ID3DXLine Object
	if(FAILED(D3DXCreateLine(pD3Ddevice, &pLine)))
	{
		throw "ID3DXLine�̍쐬�Ɏ��s���܂����B";
	}

	// Initialize DirectInput
	pInput->Init();
}

void MainThread::InitGame()
{
	AddScene("boot"); now_scene = "boot";

	if( luaL_loadfile(Ls->GetLuaState(), "LuaScript/reload.lua") || 
		lua_pcall(Ls->GetLuaState(), 0, 0, 0) )
	{
		return ;
	}

	//lua_getglobal(Ls->GetLuaState(), "InitGame");
	//if( lua_pcall(Ls->GetLuaState(), 0, 0, 0) )
	//{
	//	MessageBox(NULL, lua_tostring(Ls->GetLuaState(), -1), "Lua�t�@�C��", MB_OK);
	//	return ;
	//}

	//FindScene(now_scene)->OnStart();
}

void MainThread::BeginFrame()
{
	const DWORD WAIT_TIME = 16;	//��60FPS

	//�Ō�ɍs������������̎��Ԃ𒲂ׂ�
	DWORD ntime = timeGetTime();
	DWORD rtime = ntime - lasttime;
	lasttime = ntime;
	if(rtime < WAIT_TIME){
		//�E�F�C�g�������s��
		Sleep(WAIT_TIME - rtime);
	}

	//�摜�̃N���A
	pD3Ddevice->Clear(
		0,						// �N���A����̈�̔z���
		NULL,					// �N���A����̈�̔z��
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,	// �Ώۂ��w��̐F�ŃN���A����
		D3DCOLOR_XRGB(0,0,64),	// �N���A����F�����F�Ɏw��
		1.0f,					// z�����̃N���A�i1.0f�ł��ׂĂ��N���A�j�B
		0						// �X�e���V���o�b�t�@�̃N���A�i�g�p���Ă��Ȃ��̂�0���w��j
	);

	//�J�n�錾
	pD3Ddevice->BeginScene();
}

void MainThread::ProcessFrame()
{
	LuaScene* scene = FindScene(now_scene);
	if( scene == NULL ) return ;

	it_task = actorList.begin();
	while(it_task != actorList.end())
	{
		(*it_task)->OnFrame();
		if( !it_moved )
		{
			it_task++;
		}
		else
		{
			it_moved = false;
		}
	}
	scene->OnFrame();
}

void MainThread::DrawFrame()
{
	LuaScene* scene = FindScene(now_scene);
	if( scene == NULL ) return ;

	it_task = actorList.begin();
	while(it_task != actorList.end())
	{
		(*it_task)->OnDraw();
		if( !it_moved )
		{
			it_task++;
		}
		else
		{
			it_moved = false;
		}
	}
	scene->OnDraw();
}

void MainThread::EndFrame()
{
	// �\��
	pD3Ddevice->EndScene();
	pD3Ddevice->Present(
		NULL,	// �]�����̗̈�iNULL�őS��w��j
		NULL,	// �]����̗̈�iNULL�őS��w��j
		NULL,	// �]����̃E�B���h�E�������n���h���iNULL�ŕW���̃E�B���h�E�j
		NULL	// ���s�o�[�W�����ł͏��NULL���w��
	);

	// Update Input
	pInput->Update();
}

void MainThread::EndGame()
{
	lua_State* sL = Ls->GetLuaState();
	lua_getglobal(sL, "OnShutdown");
	if( lua_pcall(sL, 0, 0, 0) )
	{
		MessageBox(NULL, lua_tostring(sL, -1), "Lua�t�@�C��", MB_OK);
		return ;
	}
}

void MainThread::ReleaseDirectX()
{
	hash_map<string, LuaScene*>::iterator i = sceneMap.begin();
	for(; i != sceneMap.end(); i++ )
	{
		delete i->second;
	}
	sceneMap.clear();

	delete Ls;
	delete pInput;
	RELEASE(pLine);
	RELEASE(pVertex);
	RELEASE(pD3Ddevice);
	RELEASE(pD3D);
}

LuaScene* MainThread::AddScene(string scene_name)
{
	LuaScene* scene = new LuaScene(Ls, scene_name);
	sceneMap.insert( pair<string, LuaScene*>(scene_name, scene) );

	return scene;
}

void MainThread::ChangeScene(string next_scene)
{
	if( FindScene(next_scene) == NULL ) return ;

	FindScene(now_scene)->OnClose();
	now_scene = next_scene;
	FindScene(next_scene)->OnStart();
}

LuaScene* MainThread::FindScene(string scene_name)
{
	hash_map<string, LuaScene*>::iterator i;
	i = sceneMap.find(scene_name);
	
	if(i == sceneMap.end()) return NULL;
	
	return i->second;
}

void MainThread::AddActor(Actor* actor)
{
	actorList.push_back( actor );

	actor->OnStart();
}

void MainThread::DeleteActor(string actor_name)
{
	list<Actor*>::iterator it = actorList.begin();
	while( it != actorList.end() )
	{
		if( (*it)->GetActorName() == actor_name )
		{
			if( it == it_task )
			{
				it_moved = true;
				it_task++;
			}

			delete (*it);
			actorList.erase(it);
			
			return;
		}
		else
		{
			it++;
		}
	}
}

void MainThread::DeleteActorAll()
{
	list<Actor*>::iterator it = actorList.begin();
	for(; it != actorList.end(); ++it)
	{
		delete (*it);
	}
	actorList.clear();
}