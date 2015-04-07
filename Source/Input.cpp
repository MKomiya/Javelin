#include "Input.h"
#include "MainThread.h"

Input::Input(void)
{
    pInput = NULL;
    pKeyDevice = NULL;  
	pPadDevice = NULL;
}

Input::~Input(void)
{
    RELEASE(pKeyDevice);  
	RELEASE(pPadDevice);
    RELEASE(pInput); 
}

void Input::Init()
{
	if(pInput == NULL){
		// インターフェイスの取得
		HRESULT hr;
		hr = DirectInput8Create(
			MainThread::GetHInstance(),		// ソフトのインスタンスハンドル
			DIRECTINPUT_VERSION,			// DirectInputのバージョン
			IID_IDirectInput8,				// 取得するインターフェイスのタイプ
			(LPVOID*)&pInput,				// インターフェイスの格納先
			NULL							// COM集成の制御オブジェクト（使わないのでNULL）
			);

		if(FAILED(hr)){
			throw "DirectInputの初期化に失敗しました";
			return;
		}

		hr = pInput->CreateDevice(
			GUID_SysKeyboard,	// 受け付ける入力デバイス
			&pKeyDevice,		// IDirectInputDevice8格納先
			NULL				// COM集成の制御オブジェクト（使わないのでNULL）
			);

		if(FAILED(hr)){
			throw "DirectInputDeviceの初期化に失敗しました";
			return;
		}

        // データフォーマットの設定  
        pKeyDevice->SetDataFormat(&c_dfDIKeyboard);  
  
        // 協調モードの設定  
        pKeyDevice->SetCooperativeLevel(MainThread::GetHWnd(),  
            DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);  
  
        // キーバッファの初期化  
        ZeroMemory(keydata, 256); 

        // ジョイパッドの作成  
          
        // コールバック関数に転送したいデータを格納  
        enumdata ed;  
        ed.pInput = pInput;  
        ed.ppPadDevice = &pPadDevice;  
          
        pInput->EnumDevices(  
            DI8DEVCLASS_GAMECTRL,   // ゲームコントローラーが対象  
            EnumJoypad,             // 列挙する関数  
            &ed,                    // 列挙関数に渡したいデータはここに入れる  
            DIEDFL_ATTACHEDONLY     // インストール・接続済みのデバイスのみ取得  
            );  

        if(pPadDevice){  
            // アナログキーのデータを設定  
            // ２番目の引数にpPadDeviceを指定しておくと、  
            // EnumObject関数のpvRefに、このpPadDeviceが格納されるようになるため、  
            // pPadDeviceをスタティックやグローバル変数にしなくて済む。  
            pPadDevice->EnumObjects(EnumObject, pPadDevice, DIDFT_AXIS);  
  
            pPadDevice->SetCooperativeLevel(MainThread::GetHWnd(),  
                DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);  
			// ゲームパッドの入力情報はDIJOYSTATE2に格納されるので  
			// データフォーマットにはc_dfDIJoystick2を指定  
            hr = pPadDevice->SetDataFormat(&c_dfDIJoystick2);  
            if(FAILED(hr)) RELEASE(pPadDevice);  
        }
	}
}

BOOL CALLBACK Input::EnumJoypad(const DIDEVICEINSTANCE* pInstance, LPVOID pContext)  
{  
    enumdata *ed = (enumdata*)pContext;  
  
    // このプログラムは単一機器のみ接続されていることが前提。  
    // ゲームパッドが複数接続されているときに、特定の機器のみを使いたいときは  
    // それ以外のデバイスが呼び出されたときに弾くようにするとよい  
    /* 
    if(_tcscmp(pInstance->tszProductName, _T("TNK Controler")) != 0){ 
        return DIENUM_CONTINUE; 
    } 
    */  
  
    HRESULT hr;  
    hr = ed->pInput->CreateDevice  
        (pInstance->guidInstance, ed->ppPadDevice, NULL);  
    if(FAILED(hr)) return DIENUM_CONTINUE;  // デバイスが作成できないので列挙を続ける  
  
    // 希望するデバイスが作成できたので列挙を終了する  
    return DIENUM_STOP;  
} 

BOOL CALLBACK Input::EnumObject(LPCDIDEVICEOBJECTINSTANCE pInstance, LPVOID pvRef)  
{  
    DIPROPRANGE range;  
    range.diph.dwSize = sizeof(DIPROPRANGE);  
    range.diph.dwHeaderSize = sizeof(DIPROPHEADER);  
    range.diph.dwObj = pInstance->dwType;    // ボタンやスティックのデータ  
    range.diph.dwHow = DIPH_BYID;           // タイプで取得することを指定  
    range.lMin = -10;                       // 値の最小値  
    range.lMax = +10;                       // 値の最大値  
      
    LPDIRECTINPUTDEVICE8 pInputDev = (LPDIRECTINPUTDEVICE8)pvRef;  
    pInputDev->SetProperty(DIPROP_RANGE, &range.diph);  
  
    return DIENUM_CONTINUE;  
}  

void Input::Update()  
{  
    if(pKeyDevice){  
        // 入力の受け付け開始  
        pKeyDevice->Acquire();  
  
		memcpy(lastkeydata, keydata, 256); 
        // データを取得（256は取得するデータのサイズ）  
        pKeyDevice->GetDeviceState(256, keydata);  
    }

    if(pPadDevice){  
        // ジョイパッドデータの取得  
        pPadDevice->Poll();  
  
        // 入力の受付開始  
        pPadDevice->Acquire();  
  
        memcpy(&lastpaddata, &paddata, sizeof(DIJOYSTATE2));  
        pPadDevice->GetDeviceState(sizeof(DIJOYSTATE2), &paddata);  
    } 
} 

bool Input::IsKeyDown(int key)  
{  
    if(pKeyDevice == NULL) return false;  
      
    // 最上位１ビットに「押されているか」どうかのデータが格納されていることに注意  
    // 最下位１ビットには「トグル（オン・オフの状態）」が格納されている  
    return (keydata[key] & 0x80) ? true : false;  
}

bool Input::IsKeyPressed(int key)  
{  
    if(pKeyDevice == NULL) return false;  
  
    // 現在押されていてかつ直前に押されていないときTRUEを返す  
    if((keydata[key] & 0x80) && !(lastkeydata[key] & 0x80)) return true;  
    return false;  
}  
  
bool Input::IsKeyReleased(int key)  
{  
    if(pKeyDevice == NULL) return false;  
  
    // 現在押されておらずかつ直前には押されていたときTRUEを返す  
    if(!(keydata[key] & 0x80) && (lastkeydata[key] & 0x80)) return true;  
    return false;  
}

unsigned char Input::GetPovPosition()  
{  
    // paddata.rgdwPOV[0]に押された方向が角度×100という整数で格納されている  
    // 真上が0で時計回りに36000まで範囲がある  
    // デジタル入力方式のゲームパッドの場合、45度単位で取得してもまず問題ない  
    switch(paddata.rgdwPOV[0]){  
        case 0:  
            return PP_UP;  
        case 4500:  
            return PP_UP | PP_RIGHT;  
        case 9000:  
            return PP_RIGHT;  
        case 13500:  
            return PP_RIGHT | PP_DOWN;  
        case 18000:  
            return PP_DOWN;  
        case 22500:  
            return PP_DOWN | PP_LEFT;  
        case 27000:  
            return PP_LEFT;  
        case 31500:  
            return PP_LEFT | PP_UP;  
    }  
  
    // アナログ入力から判断  
    BYTE result = 0x0;  
    if(paddata.lX > 5) result |= PP_RIGHT;  
    else if(paddata.lX < -5) result |= PP_LEFT;  
    if(paddata.lY > 5) result |= PP_DOWN;  
    else if(paddata.lY < -5) result |= PP_UP;  

    return result;  
}  
  
bool Input::IsButtonDown(int pos)  
{  
    if(pPadDevice == NULL) return false;  
    return ( paddata.rgbButtons[pos] > 0);  
}  
  
bool Input::IsButtonPressed(int pos)  
{  
    if(pPadDevice == NULL) return false;  
  
    if(paddata.rgbButtons[pos] && !lastpaddata.rgbButtons[pos]) return true;  
    return false;  
}  
  
bool Input::IsButtonReleased(int pos)  
{  
    if(pPadDevice == NULL) return false;  
  
    if(!paddata.rgbButtons[pos] && lastpaddata.rgbButtons[pos]) return true;  
    return false;  
}  