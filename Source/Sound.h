#pragma once
#include "gameobject.h"

// DirectSound���g�����߂̃w�b�_��`�ƃ��C�u���������N�̎w��  
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

    // �Đ��I�����֒m  
    LPDIRECTSOUNDNOTIFY pDSNotify;  
    HANDLE hEvent; 

	void Reset();

    // �V�K�X���b�h�ɗp����֐�  
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