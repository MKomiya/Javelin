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
		// �C���^�[�t�F�C�X�̎擾
		HRESULT hr;
		hr = DirectInput8Create(
			MainThread::GetHInstance(),		// �\�t�g�̃C���X�^���X�n���h��
			DIRECTINPUT_VERSION,			// DirectInput�̃o�[�W����
			IID_IDirectInput8,				// �擾����C���^�[�t�F�C�X�̃^�C�v
			(LPVOID*)&pInput,				// �C���^�[�t�F�C�X�̊i�[��
			NULL							// COM�W���̐���I�u�W�F�N�g�i�g��Ȃ��̂�NULL�j
			);

		if(FAILED(hr)){
			throw "DirectInput�̏������Ɏ��s���܂���";
			return;
		}

		hr = pInput->CreateDevice(
			GUID_SysKeyboard,	// �󂯕t������̓f�o�C�X
			&pKeyDevice,		// IDirectInputDevice8�i�[��
			NULL				// COM�W���̐���I�u�W�F�N�g�i�g��Ȃ��̂�NULL�j
			);

		if(FAILED(hr)){
			throw "DirectInputDevice�̏������Ɏ��s���܂���";
			return;
		}

        // �f�[�^�t�H�[�}�b�g�̐ݒ�  
        pKeyDevice->SetDataFormat(&c_dfDIKeyboard);  
  
        // �������[�h�̐ݒ�  
        pKeyDevice->SetCooperativeLevel(MainThread::GetHWnd(),  
            DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);  
  
        // �L�[�o�b�t�@�̏�����  
        ZeroMemory(keydata, 256); 

        // �W���C�p�b�h�̍쐬  
          
        // �R�[���o�b�N�֐��ɓ]���������f�[�^���i�[  
        enumdata ed;  
        ed.pInput = pInput;  
        ed.ppPadDevice = &pPadDevice;  
          
        pInput->EnumDevices(  
            DI8DEVCLASS_GAMECTRL,   // �Q�[���R���g���[���[���Ώ�  
            EnumJoypad,             // �񋓂���֐�  
            &ed,                    // �񋓊֐��ɓn�������f�[�^�͂����ɓ����  
            DIEDFL_ATTACHEDONLY     // �C���X�g�[���E�ڑ��ς݂̃f�o�C�X�̂ݎ擾  
            );  

        if(pPadDevice){  
            // �A�i���O�L�[�̃f�[�^��ݒ�  
            // �Q�Ԗڂ̈�����pPadDevice���w�肵�Ă����ƁA  
            // EnumObject�֐���pvRef�ɁA����pPadDevice���i�[�����悤�ɂȂ邽�߁A  
            // pPadDevice���X�^�e�B�b�N��O���[�o���ϐ��ɂ��Ȃ��čςށB  
            pPadDevice->EnumObjects(EnumObject, pPadDevice, DIDFT_AXIS);  
  
            pPadDevice->SetCooperativeLevel(MainThread::GetHWnd(),  
                DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);  
			// �Q�[���p�b�h�̓��͏���DIJOYSTATE2�Ɋi�[�����̂�  
			// �f�[�^�t�H�[�}�b�g�ɂ�c_dfDIJoystick2���w��  
            hr = pPadDevice->SetDataFormat(&c_dfDIJoystick2);  
            if(FAILED(hr)) RELEASE(pPadDevice);  
        }
	}
}

BOOL CALLBACK Input::EnumJoypad(const DIDEVICEINSTANCE* pInstance, LPVOID pContext)  
{  
    enumdata *ed = (enumdata*)pContext;  
  
    // ���̃v���O�����͒P��@��̂ݐڑ�����Ă��邱�Ƃ��O��B  
    // �Q�[���p�b�h�������ڑ�����Ă���Ƃ��ɁA����̋@��݂̂��g�������Ƃ���  
    // ����ȊO�̃f�o�C�X���Ăяo���ꂽ�Ƃ��ɒe���悤�ɂ���Ƃ悢  
    /* 
    if(_tcscmp(pInstance->tszProductName, _T("TNK Controler")) != 0){ 
        return DIENUM_CONTINUE; 
    } 
    */  
  
    HRESULT hr;  
    hr = ed->pInput->CreateDevice  
        (pInstance->guidInstance, ed->ppPadDevice, NULL);  
    if(FAILED(hr)) return DIENUM_CONTINUE;  // �f�o�C�X���쐬�ł��Ȃ��̂ŗ񋓂𑱂���  
  
    // ��]����f�o�C�X���쐬�ł����̂ŗ񋓂��I������  
    return DIENUM_STOP;  
} 

BOOL CALLBACK Input::EnumObject(LPCDIDEVICEOBJECTINSTANCE pInstance, LPVOID pvRef)  
{  
    DIPROPRANGE range;  
    range.diph.dwSize = sizeof(DIPROPRANGE);  
    range.diph.dwHeaderSize = sizeof(DIPROPHEADER);  
    range.diph.dwObj = pInstance->dwType;    // �{�^����X�e�B�b�N�̃f�[�^  
    range.diph.dwHow = DIPH_BYID;           // �^�C�v�Ŏ擾���邱�Ƃ��w��  
    range.lMin = -10;                       // �l�̍ŏ��l  
    range.lMax = +10;                       // �l�̍ő�l  
      
    LPDIRECTINPUTDEVICE8 pInputDev = (LPDIRECTINPUTDEVICE8)pvRef;  
    pInputDev->SetProperty(DIPROP_RANGE, &range.diph);  
  
    return DIENUM_CONTINUE;  
}  

void Input::Update()  
{  
    if(pKeyDevice){  
        // ���͂̎󂯕t���J�n  
        pKeyDevice->Acquire();  
  
		memcpy(lastkeydata, keydata, 256); 
        // �f�[�^���擾�i256�͎擾����f�[�^�̃T�C�Y�j  
        pKeyDevice->GetDeviceState(256, keydata);  
    }

    if(pPadDevice){  
        // �W���C�p�b�h�f�[�^�̎擾  
        pPadDevice->Poll();  
  
        // ���͂̎�t�J�n  
        pPadDevice->Acquire();  
  
        memcpy(&lastpaddata, &paddata, sizeof(DIJOYSTATE2));  
        pPadDevice->GetDeviceState(sizeof(DIJOYSTATE2), &paddata);  
    } 
} 

bool Input::IsKeyDown(int key)  
{  
    if(pKeyDevice == NULL) return false;  
      
    // �ŏ�ʂP�r�b�g�Ɂu������Ă��邩�v�ǂ����̃f�[�^���i�[����Ă��邱�Ƃɒ���  
    // �ŉ��ʂP�r�b�g�ɂ́u�g�O���i�I���E�I�t�̏�ԁj�v���i�[����Ă���  
    return (keydata[key] & 0x80) ? true : false;  
}

bool Input::IsKeyPressed(int key)  
{  
    if(pKeyDevice == NULL) return false;  
  
    // ���݉�����Ă��Ă����O�ɉ�����Ă��Ȃ��Ƃ�TRUE��Ԃ�  
    if((keydata[key] & 0x80) && !(lastkeydata[key] & 0x80)) return true;  
    return false;  
}  
  
bool Input::IsKeyReleased(int key)  
{  
    if(pKeyDevice == NULL) return false;  
  
    // ���݉�����Ă��炸�����O�ɂ͉�����Ă����Ƃ�TRUE��Ԃ�  
    if(!(keydata[key] & 0x80) && (lastkeydata[key] & 0x80)) return true;  
    return false;  
}

unsigned char Input::GetPovPosition()  
{  
    // paddata.rgdwPOV[0]�ɉ����ꂽ�������p�x�~100�Ƃ��������Ŋi�[����Ă���  
    // �^�オ0�Ŏ��v����36000�܂Ŕ͈͂�����  
    // �f�W�^�����͕����̃Q�[���p�b�h�̏ꍇ�A45�x�P�ʂŎ擾���Ă��܂����Ȃ�  
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
  
    // �A�i���O���͂��画�f  
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