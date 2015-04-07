/**
 * DirectInput8による入力部分を扱うクラス
 * キーボード、ゲームパッドアナログ入力まで対応
 */
#pragma once
  
#define DIRECTINPUT_VERSION 0x0800  
#include <dinput.h>  
#pragma comment(lib, "dinput8.lib")  
#pragma comment(lib, "dxguid.lib")  

/**
 * パッドの方向キー用
 */
#define PP_UP 0x1  
#define PP_RIGHT 0x2  
#define PP_DOWN 0x4  
#define PP_LEFT 0x8  

/**
 * デバイス列挙関数に渡すデータを格納する構造体  
 */
struct enumdata  
{  
    LPDIRECTINPUT8 pInput;              //!< デバイスを作成するためのインターフェイス  
    LPDIRECTINPUTDEVICE8 *ppPadDevice;  //!< 使用するデバイスを格納するポインタのポインタ  
};

class Input
{
private:  
    LPDIRECTINPUT8 pInput;  
  
    LPDIRECTINPUTDEVICE8 pKeyDevice;  
    BYTE keydata[256], lastkeydata[256];

    LPDIRECTINPUTDEVICE8 pPadDevice;  
    DIJOYSTATE2 paddata, lastpaddata;  
  
    static BOOL CALLBACK EnumJoypad(const DIDEVICEINSTANCE* pInstance, LPVOID pContext);
	static BOOL CALLBACK EnumObject(LPCDIDEVICEOBJECTINSTANCE pInstance, LPVOID pvRef); 
  
public:  
    bool IsKeyDown(int key);
    bool IsKeyPressed(int key);  
    bool IsKeyReleased(int key);

    unsigned char GetPovPosition();          // 十字キーの位置を取得  
    bool IsButtonDown(int pos);     // ボタンが押され続けているか  
    bool IsButtonPressed(int pos);  // ボタンが押された瞬間か  
    bool IsButtonReleased(int pos); // ボタンが放された瞬間か  

	void Init();
	void Update();

public:
	Input(void);
	~Input(void);
};

