/**
 * DirectInput8�ɂ����͕����������N���X
 * �L�[�{�[�h�A�Q�[���p�b�h�A�i���O���͂܂őΉ�
 */
#pragma once
  
#define DIRECTINPUT_VERSION 0x0800  
#include <dinput.h>  
#pragma comment(lib, "dinput8.lib")  
#pragma comment(lib, "dxguid.lib")  

/**
 * �p�b�h�̕����L�[�p
 */
#define PP_UP 0x1  
#define PP_RIGHT 0x2  
#define PP_DOWN 0x4  
#define PP_LEFT 0x8  

/**
 * �f�o�C�X�񋓊֐��ɓn���f�[�^���i�[����\����  
 */
struct enumdata  
{  
    LPDIRECTINPUT8 pInput;              //!< �f�o�C�X���쐬���邽�߂̃C���^�[�t�F�C�X  
    LPDIRECTINPUTDEVICE8 *ppPadDevice;  //!< �g�p����f�o�C�X���i�[����|�C���^�̃|�C���^  
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

    unsigned char GetPovPosition();          // �\���L�[�̈ʒu���擾  
    bool IsButtonDown(int pos);     // �{�^���������ꑱ���Ă��邩  
    bool IsButtonPressed(int pos);  // �{�^���������ꂽ�u�Ԃ�  
    bool IsButtonReleased(int pos); // �{�^���������ꂽ�u�Ԃ�  

	void Init();
	void Update();

public:
	Input(void);
	~Input(void);
};

