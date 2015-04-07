/**
 * ���C���X���b�h�̏������܂Ƃ߁AWin32API���ӎ����Ȃ��������܂Ƃ߂��N���X
 * DirectX�֌W�̏������������ōs�Ȃ��Ă���
 * �����l�߉߂��Ƃ�������
 * �ÓI�����o�吙�Ƃ�������
 */
#pragma once
#include "stdafx.h"

class Input;
class LuaStatement;
class LuaScene;
class Actor;

class MainThread
{
// ���_�f�[�^�֌W
public:
	static const DWORD FVF_CUSTOM = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;
	static struct CUSTOMVERTEX
	{
		float x, y, z;	//!< @brief ���_���W
		float rhw;		//!< @brief ���Z��
		D3DCOLOR color;	//!< @brief ���_�J���[
		float u, v;		//!< @brief �e�N�X�`�����W
	};

// �E�B���h�E�ƃC���X�^���X�̃n���h��
private:
	static HWND hWnd;
	static HINSTANCE hInstance;
public:
	static const HWND GetHWnd() { return hWnd; }
	static const HINSTANCE GetHInstance(){ return hInstance; }

// DirectX���ʃ|�C���^�Q
private:
	static LPDIRECT3D9 pD3D;
	static LPDIRECT3DDEVICE9 pD3Ddevice;
	static IDirect3DVertexBuffer9 *pVertex;
	static ID3DXLine *pLine;
public:
	static LPDIRECT3D9 GetD3D() { return pD3D; }
	static LPDIRECT3DDEVICE9 GetDevice() { return pD3Ddevice; }
	static IDirect3DVertexBuffer9* GetVertex() { return pVertex; }
	static ID3DXLine* GetLine() { return pLine; }

private:
	bool request_quit;
	DWORD lasttime;

// DirectInput8���b�p�[�֌W
private:
	static Input* pInput;
public:
	static Input* GetInput() { return pInput; }

// Lua�֌W
private:
	static LuaStatement* Ls;
public:
	static LuaStatement* GetLs() { return Ls; }

private:
	static hash_map<string, LuaScene*> sceneMap;
	static string now_scene;
	static list<Actor*> actorList;
	static bool it_moved;
	static list<Actor*>::iterator it_task;

public:
	static LuaScene* AddScene(string scene_name);
	static void ChangeScene(string next_scene);
	static LuaScene* FindScene(string scene_name);

	static void AddActor(Actor* actor);
	static void DeleteActor(string actor_name);
	static void DeleteActorAll();

// ���C���̏����Q
public:
	MainThread(HWND hWnd, HINSTANCE hInstance);

	void Run();

	void InitDirectX();
	void InitGame();

	void BeginFrame();
	void ProcessFrame();
	void DrawFrame();
	void EndFrame();

	void EndGame();
	void ReleaseDirectX();
};

