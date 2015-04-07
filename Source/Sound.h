#pragma once
#include "gameobject.h"

// DirectSoundを使うためのヘッダ定義とライブラリリンクの指示  
#include <dsound.h>  
#pragma comment(lib, "dsound.lib")  
#pragma comment(lib, "dxguid.lib")   

class Sound :
	public GameObject
{
private:  
    friend int APIENTRY _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int);  
    static LPDIRECTSOUND8 pDSound;  
    static void CreateDirectSound(HWND hWnd);  
    static void ReleaseDirectSound(); 

    LPDIRECTSOUNDBUFFER pDSBuffer;  

    // 再生終了を関知  
    LPDIRECTSOUNDNOTIFY pDSNotify;  
    HANDLE hEvent; 

	void Reset();

    // 新規スレッドに用いる関数  
    static DWORD WINAPI NotifyFunction(LPVOID param);
  
public:  
    Sound();  
    Sound(LPCTSTR filename);  
    ~Sound();
	Sound& operator=(const Sound&);
	Sound(const Sound&);
  
    BOOL Load(LPCTSTR filename);  
	void Play();
    void Stop();  
    void SetVolume(LONG volume);  
    void SetPan(LONG lPan); 

	void EnableDeleteByEnd(); 
};