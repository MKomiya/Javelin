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
        CLSID_FilterGraph,      // COMの識別子  
        NULL,                   // 特別に取得する情報はないのでNULL  
        CLSCTX_INPROC_SERVER,   // このプログラム内でのみ使うことを指定  
        IID_IGraphBuilder,      // 取得するインターフェース  
        (LPVOID*)&pBuilder);    // 格納先  
  
    if(FAILED(hr)){  
        //DXTRACE_MSG(_T("IGraphBuilderの作成に失敗しました"));  
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
        bLoop = loop;   // ループ再生を行うかのフラグ  
        if(pMediaSeeking)
		{  
            // 再生位置を先頭に移動する  
            LONGLONG s = 0;  
            pMediaSeeking->SetPositions(  
                // 再生位置は絶対位置で(s * 100)ナノ秒  
                &s, AM_SEEKING_AbsolutePositioning,  
                // 終了位置は変更しないのでNoPositioningを指定  
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
        pMediaSeeking->GetPositions(&s, &e); // sは開始位置、eは終了位置  
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
        // 差分で経過時間を取得  
        float t = (float)timeGetTime() - time_s;  
        pBasicAudio->put_Volume((long)(delta * t + vol_s));  
  
        // 経過時間を超えたらフェード処理終了  
        if(t >= time_e) bFading = FALSE;  
    }  
}

void BGMusic::Fade(unsigned long endtime, long volume)  
{  
    if(!pBasicAudio)
	{  
        //DXTRACE_MSG(_T("ボリュームの設定ができません。"));  
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