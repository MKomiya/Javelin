#include "DebugPut.h"
#include "MainThread.h"

/** ウィンドウイベントを処理する関数
 * hWnd     : イベントが発生したウィンドウのハンドル
 * msg      : 発生したイベントの内容
 * wParam   : イベントから通知されたデータ（イベントにより内容は異なります）
 * lParam   : イベントから通知されたデータ（イベントにより内容は異なります）  
 */
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)  
{  
    switch (msg) {  
        case WM_DESTROY:  
            // ウィンドウが閉じられたときにこの部分が実行される  
            PostQuitMessage(NULL);  
            // プログラムの終了をシステムに通知する関数です  
            // カッコ内の数値は終了イベント（WM_QUIT）に  
            // 通知したいデータを格納します  
            // （今回は通知するデータはないのでNULL）
            break;
		case WM_KEYDOWN:
			// 特別なキー入力時の処理
			switch( wParam ) {
				case VK_ESCAPE:
					if( MessageBox(hWnd, "本当に終了しますか？", "Javelin System", MB_ICONQUESTION | MB_YESNO ) == IDYES )
					{
						SendMessage( hWnd, WM_DESTROY, 0, 0 );
					}
					break;
			}
			break;
        default:
            // 作成するプログラムに必要のないイベントであれば
            // システムにイベント処理を丸投げする命令で対処する
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
	p.PutLogTopic("WIN32APIの初期化処理");

	CoInitialize(NULL);

	// 警告の抑制
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpszCmdLine);

	timeBeginPeriod(1);

	MyRegisterClass(hInstance);
	p.PutLog("ウィンドウハンドルの登録に成功しました");

	MSG msg;
    HWND hWnd = CreateWindow(  
		"S.W.Game",       // 登録したクラス名  
        "Javelin Game System",  
            // ウィンドウに表示するタイトル  
        WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,  
            // ウィンドウのスタイル  
            // （タイトルバー、システムメニュー、最小化ボタンを使用）  
        CW_USEDEFAULT,  // ウィンドウのx位置（システム標準値を使用）  
        CW_USEDEFAULT,  // ウィンドウのy位置（システム標準値を使用）  
        640,            // ウィンドウの幅  
        480,            // ウィンドウの高さ  
        NULL,  
            // 親ウィンドウのハンドル
            // このプログラムに親ウィンドウは存在しないのでNULLを渡します  
        NULL,  
            // メニューハンドル  
            // このプログラムにメニューは存在しないのでNULLを渡します  
        hInstance,      // インスタンスハンドル  
        NULL  
            // ウィンドウ作成時のイベントへ渡すデータのポインタ  
            // 渡すデータはないのでNULLを指定します  
        );
	p.PutLog("CreateWindowに成功しました");
	p.PutLog("以下、Direct3Dの初期化に移ります");

	MainThread thread(hWnd, hInstance);
	try
	{
		thread.InitDirectX();
	}
	catch(LPCTSTR str)
	{
		p.PutLog("例外がスローされました");
		MessageBox(0, str, TEXT("Error"), MB_OK);	// 例外文字列を表示
		DestroyWindow(hWnd);
		p.PutLog("ウィンドウを破棄します");
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


    // ウィンドウを表示します  
    // hWnd : 表示するウィンドウのハンドル  
    // nCmdShow : 最初のウィンドウの状態  
    //            ここではショートカットなどから報告された  
    //            初期ウィンドウ状態の指定を利用しています  
    ShowWindow(hWnd, nCmdShow);
	ValidateRect(hWnd, 0);
	UpdateWindow(hWnd);
	p.PutLog("ウィンドウ表示に成功しました");

	ZeroMemory(&msg, sizeof(msg));

	// 例外を受けたら終了できるように
	try
	{
		p.PutLogTopic("ゲーム開始");
		p.PutLogTopic("ゲーム情報を初期化します");
		thread.InitGame();

		p.PutLog("メインループを開始します");
		// ウィンドウが閉じられるまで永久にループさせます    
		while(msg.message!=WM_QUIT){  
			// ウィンドウに通達されようとしているイベントを取得  
			if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{    
				// 仮想キーメッセージを文字メッセージへ変換します  
				TranslateMessage(&msg);  
				// 実際にウィンドウへイベントを通達  
				DispatchMessage(&msg);  
			}
			else
			{  
				// イベントが発生していなかったのなら  
				// ここで空き時間に行いたい処理内容を記述  
				thread.Run();
			}  
		}
	}
	catch(LPCTSTR str)
	{
		p.PutLog("例外がスローされました");
		MessageBox(0, str, TEXT("Error"), MB_OK);	// 例外文字列を表示
		DestroyWindow(hWnd);
		p.PutLog("ウィンドウを破棄します");
	}
	catch(...)
	{
		p.PutLog("アンノウンの例外がスローされました");
		MessageBox(0, TEXT("unknown error"), TEXT("Error"), MB_OK);
		DestroyWindow(hWnd);
		p.PutLog("ウィンドウを破棄します");
	}

	p.PutLogTopic("ゲーム終了");
	thread.EndGame();

	p.PutLog("解放処理に移ります");
	thread.ReleaseDirectX();

	CoUninitialize();

	p.PutLogTopic("WIN32APIの解放処理");
	p.PutLog("ウィンドウを破棄します");
	p.LogEnd();

	return (int)msg.wParam;
}