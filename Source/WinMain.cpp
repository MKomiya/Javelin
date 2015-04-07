#include "DebugPut.h"
#include "MainThread.h"

/** �E�B���h�E�C�x���g����������֐�
 * hWnd     : �C�x���g�����������E�B���h�E�̃n���h��
 * msg      : ���������C�x���g�̓��e
 * wParam   : �C�x���g����ʒm���ꂽ�f�[�^�i�C�x���g�ɂ����e�͈قȂ�܂��j
 * lParam   : �C�x���g����ʒm���ꂽ�f�[�^�i�C�x���g�ɂ����e�͈قȂ�܂��j  
 */
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)  
{  
    switch (msg) {  
        case WM_DESTROY:  
            // �E�B���h�E������ꂽ�Ƃ��ɂ��̕��������s�����  
            PostQuitMessage(NULL);  
            // �v���O�����̏I�����V�X�e���ɒʒm����֐��ł�  
            // �J�b�R���̐��l�͏I���C�x���g�iWM_QUIT�j��  
            // �ʒm�������f�[�^���i�[���܂�  
            // �i����͒ʒm����f�[�^�͂Ȃ��̂�NULL�j
            break;
		case WM_KEYDOWN:
			// ���ʂȃL�[���͎��̏���
			switch( wParam ) {
				case VK_ESCAPE:
					if( MessageBox(hWnd, "�{���ɏI�����܂����H", "Javelin System", MB_ICONQUESTION | MB_YESNO ) == IDYES )
					{
						SendMessage( hWnd, WM_DESTROY, 0, 0 );
					}
					break;
			}
			break;
        default:
            // �쐬����v���O�����ɕK�v�̂Ȃ��C�x���g�ł����
            // �V�X�e���ɃC�x���g�������ۓ������閽�߂őΏ�����
            return (DefWindowProc(hWnd, msg, wParam, lParam));
    }  
    return (0);
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= "S.W.Game";
	wcex.hIconSm		= NULL;

	return RegisterClassEx(&wcex);
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  
	DebugPut p; p.LogInit();
	p.PutLogTopic("WIN32API�̏���������");

	CoInitialize(NULL);

	// �x���̗}��
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpszCmdLine);

	timeBeginPeriod(1);

	MyRegisterClass(hInstance);
	p.PutLog("�E�B���h�E�n���h���̓o�^�ɐ������܂���");

	MSG msg;
    HWND hWnd = CreateWindow(  
		"S.W.Game",       // �o�^�����N���X��  
        "Javelin Game System",  
            // �E�B���h�E�ɕ\������^�C�g��  
        WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,  
            // �E�B���h�E�̃X�^�C��  
            // �i�^�C�g���o�[�A�V�X�e�����j���[�A�ŏ����{�^�����g�p�j  
        CW_USEDEFAULT,  // �E�B���h�E��x�ʒu�i�V�X�e���W���l���g�p�j  
        CW_USEDEFAULT,  // �E�B���h�E��y�ʒu�i�V�X�e���W���l���g�p�j  
        640,            // �E�B���h�E�̕�  
        480,            // �E�B���h�E�̍���  
        NULL,  
            // �e�E�B���h�E�̃n���h��
            // ���̃v���O�����ɐe�E�B���h�E�͑��݂��Ȃ��̂�NULL��n���܂�  
        NULL,  
            // ���j���[�n���h��  
            // ���̃v���O�����Ƀ��j���[�͑��݂��Ȃ��̂�NULL��n���܂�  
        hInstance,      // �C���X�^���X�n���h��  
        NULL  
            // �E�B���h�E�쐬���̃C�x���g�֓n���f�[�^�̃|�C���^  
            // �n���f�[�^�͂Ȃ��̂�NULL���w�肵�܂�  
        );
	p.PutLog("CreateWindow�ɐ������܂���");
	p.PutLog("�ȉ��ADirect3D�̏������Ɉڂ�܂�");

	MainThread thread(hWnd, hInstance);
	try
	{
		thread.InitDirectX();
	}
	catch(LPCTSTR str)
	{
		p.PutLog("��O���X���[����܂���");
		MessageBox(0, str, TEXT("Error"), MB_OK);	// ��O�������\��
		DestroyWindow(hWnd);
		p.PutLog("�E�B���h�E��j�����܂�");
	}

	RECT r1, r2;
	int ww, wh, x, y;
	GetClientRect(hWnd, &r1);  
	GetWindowRect(hWnd, &r2);
	ww = 640 + ((r2.right - r2.left) - (r1.right - r1.left));
	wh = 480 + ((r2.bottom - r2.top) - (r1.bottom - r1.top));
	x = ( GetSystemMetrics(SM_CXSCREEN) - ww ) / 2;
	y = ( GetSystemMetrics(SM_CYSCREEN) - wh ) / 2;
	SetWindowPos(hWnd, HWND_TOP, x, y, ww, wh, NULL);


    // �E�B���h�E��\�����܂�  
    // hWnd : �\������E�B���h�E�̃n���h��  
    // nCmdShow : �ŏ��̃E�B���h�E�̏��  
    //            �����ł̓V���[�g�J�b�g�Ȃǂ���񍐂��ꂽ  
    //            �����E�B���h�E��Ԃ̎w��𗘗p���Ă��܂�  
    ShowWindow(hWnd, nCmdShow);
	ValidateRect(hWnd, 0);
	UpdateWindow(hWnd);
	p.PutLog("�E�B���h�E�\���ɐ������܂���");

	ZeroMemory(&msg, sizeof(msg));

	// ��O���󂯂���I���ł���悤��
	try
	{
		p.PutLogTopic("�Q�[���J�n");
		p.PutLogTopic("�Q�[���������������܂�");
		thread.InitGame();

		p.PutLog("���C�����[�v���J�n���܂�");
		// �E�B���h�E��������܂ŉi�v�Ƀ��[�v�����܂�    
		while(msg.message!=WM_QUIT){  
			// �E�B���h�E�ɒʒB����悤�Ƃ��Ă���C�x���g���擾  
			if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{    
				// ���z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ����܂�  
				TranslateMessage(&msg);  
				// ���ۂɃE�B���h�E�փC�x���g��ʒB  
				DispatchMessage(&msg);  
			}
			else
			{  
				// �C�x���g���������Ă��Ȃ������̂Ȃ�  
				// �����ŋ󂫎��Ԃɍs�������������e���L�q  
				thread.Run();
			}  
		}
	}
	catch(LPCTSTR str)
	{
		p.PutLog("��O���X���[����܂���");
		MessageBox(0, str, TEXT("Error"), MB_OK);	// ��O�������\��
		DestroyWindow(hWnd);
		p.PutLog("�E�B���h�E��j�����܂�");
	}
	catch(...)
	{
		p.PutLog("�A���m�E���̗�O���X���[����܂���");
		MessageBox(0, TEXT("unknown error"), TEXT("Error"), MB_OK);
		DestroyWindow(hWnd);
		p.PutLog("�E�B���h�E��j�����܂�");
	}

	p.PutLogTopic("�Q�[���I��");
	thread.EndGame();

	p.PutLog("��������Ɉڂ�܂�");
	thread.ReleaseDirectX();

	CoUninitialize();

	p.PutLogTopic("WIN32API�̉������");
	p.PutLog("�E�B���h�E��j�����܂�");
	p.LogEnd();

	return (int)msg.wParam;
}