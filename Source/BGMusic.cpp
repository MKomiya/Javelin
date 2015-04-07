#include "BGMusic.h"

void BGMusic::InitializeBGM()
{
    pBuilder = NULL;  
    pMediaCtrl = NULL;  
    pMediaSeeking = NULL;  
    pBasicAudio = NULL;  
  
    bLoop = FALSE;  
    bFading = FALSE;
}

void BGMusic::Release()
{
    RELEASE(pBasicAudio);  
    RELEASE(pMediaSeeking);  
    RELEASE(pMediaCtrl);  
    RELEASE(pBuilder);
}

BGMusic::BGMusic(void)
{
	InitializeBGM();
}

BGMusic::BGMusic(const char* filename)
{
    InitializeBGM();  
    Load(filename);
}

BGMusic::~BGMusic(void)
{
	Release();
}

void BGMusic::Load(const char* filename)  
{  
    Release();  
  
    HRESULT hr = CoCreateInstance(  
        CLSID_FilterGraph,      // COM�̎��ʎq  
        NULL,                   // ���ʂɎ擾������͂Ȃ��̂�NULL  
        CLSCTX_INPROC_SERVER,   // ���̃v���O�������ł̂ݎg�����Ƃ��w��  
        IID_IGraphBuilder,      // �擾����C���^�[�t�F�[�X  
        (LPVOID*)&pBuilder);    // �i�[��  
  
    if(FAILED(hr)){  
        //DXTRACE_MSG(_T("IGraphBuilder�̍쐬�Ɏ��s���܂���"));  
        return;  
    }  
  
#ifdef _UNICODE  
    pBuilder->RenderFile(filename, NULL);  
#else  
	wchar_t wfname[MAX_PATH];  
	MultiByteToWideChar(CP_ACP, 0, filename, -1, wfname, MAX_PATH);  
	pBuilder->RenderFile(wfname, NULL);
#endif
  
    pBuilder->QueryInterface(IID_IMediaControl, (LPVOID*)&pMediaCtrl);  
    pBuilder->QueryInterface(IID_IMediaSeeking, (LPVOID*)&pMediaSeeking);  
    pBuilder->QueryInterface(IID_IBasicAudio, (LPVOID*)&pBasicAudio);  
}

void BGMusic::Play(bool loop)  
{  
    if(pMediaCtrl)
	{  
        bLoop = loop;   // ���[�v�Đ����s�����̃t���O  
        if(pMediaSeeking)
		{  
            // �Đ��ʒu��擪�Ɉړ�����  
            LONGLONG s = 0;  
            pMediaSeeking->SetPositions(  
                // �Đ��ʒu�͐�Έʒu��(s * 100)�i�m�b  
                &s, AM_SEEKING_AbsolutePositioning,  
                // �I���ʒu�͕ύX���Ȃ��̂�NoPositioning���w��  
                NULL, AM_SEEKING_NoPositioning);  
        }  
        pMediaCtrl->Run();  
    } 
}  
  
void BGMusic::Stop()  
{  
    if(pMediaCtrl) pMediaCtrl->Stop();  
}  

void BGMusic::SetVolume(long volume)  
{  
    if(pBasicAudio) pBasicAudio->put_Volume(volume);  
}  

void BGMusic::Update()  
{  
    if(bLoop == TRUE && pMediaSeeking)
	{  
        LONGLONG s, e;  
        pMediaSeeking->GetPositions(&s, &e); // s�͊J�n�ʒu�Ae�͏I���ʒu  
        if(s >= e)
		{  
            s = 0;  
            pMediaSeeking->SetPositions(  
                &s, AM_SEEKING_AbsolutePositioning,  
                NULL, AM_SEEKING_NoPositioning);  
        }  
    }

    if(bFading == TRUE)
	{  
        // �����Ōo�ߎ��Ԃ��擾  
        float t = (float)timeGetTime() - time_s;  
        pBasicAudio->put_Volume((long)(delta * t + vol_s));  
  
        // �o�ߎ��Ԃ𒴂�����t�F�[�h�����I��  
        if(t >= time_e) bFading = FALSE;  
    }  
}

void BGMusic::Fade(unsigned long endtime, long volume)  
{  
    if(!pBasicAudio)
	{  
        //DXTRACE_MSG(_T("�{�����[���̐ݒ肪�ł��܂���B"));  
        return;  
    }  
  
    bFading = TRUE;  
  
    LONG v;  
    pBasicAudio->get_Volume(&v);  
  
    vol_s = (float)v;  
    float vol_e = (float)volume;  
  
    time_s = (float)timeGetTime();  
    time_e = (float)endtime;  
  
    delta = (vol_e - vol_s) / time_e;  
} 