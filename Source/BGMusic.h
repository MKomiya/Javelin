#pragma once
#include "stdafx.h"

#include <strmif.h>  
#include <control.h>  
#include <uuids.h>  
#pragma comment (lib,"strmiids.lib")  

class BGMusic
{
private:  
    IGraphBuilder *pBuilder;  
    IMediaControl *pMediaCtrl;  
    IMediaSeeking *pMediaSeeking;  
    IBasicAudio *pBasicAudio;  
  
	BOOL bLoop, bFading;
	float time_s, time_e, vol_s, delta;

    void InitializeBGM();  
    void Release();  

public:
	BGMusic(void);
	BGMusic(const char* filename);  
	~BGMusic(void);

    void Load(const char* filename);  
    void Play(bool loop=false);  
    void Stop();

	void SetVolume(long volume);
	void Fade(unsigned long endtime, long volume);
	void Update();
};

