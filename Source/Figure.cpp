#include "Figure.h"
#include "MainThread.h"

Figure::Figure(void)
{
}

Figure::~Figure(void)
{
}

void Figure::DrawLine(int x1, int y1, int x2, int y2, unsigned long color)
{
	D3DXVECTOR2 vec[] =
	{
		D3DXVECTOR2((FLOAT)x1, (FLOAT)y1), // ラインの始点
		D3DXVECTOR2((FLOAT)x2, (FLOAT)y2) // ラインの終点
	};

	MainThread::GetLine()->Begin();
	MainThread::GetLine()->Draw(vec, 2, color);
	MainThread::GetLine()->End();
}

void Figure::DrawBox(int x, int y, int width, int height, unsigned long color)
{
	D3DXVECTOR2 vec[4][2] =
	{
		{ D3DXVECTOR2((FLOAT)x, (FLOAT)y),
		  D3DXVECTOR2((FLOAT)(x+width), (FLOAT)y) },
		{ D3DXVECTOR2((FLOAT)(x+width), (FLOAT)y),
		  D3DXVECTOR2((FLOAT)(x+width), (FLOAT)(y+height)) },
		{ D3DXVECTOR2((FLOAT)(x+width), (FLOAT)(y+height)),
		  D3DXVECTOR2((FLOAT)x, (FLOAT)(y+height)) },
		{ D3DXVECTOR2((FLOAT)x, (FLOAT)(y+height)),
		  D3DXVECTOR2((FLOAT)x, (FLOAT)y) }
	};

	MainThread::GetLine()->Begin();
	for(int i=0; i<4; i++)
	{
		MainThread::GetLine()->Draw(vec[i], 2, color);
	}
	MainThread::GetLine()->End();
}

void Figure::DrawFillBox(int x, int y, int width, int height, unsigned long color)
{
	MainThread::CUSTOMVERTEX v[4] =
	{
		{ (float)x          , (float)y           , 0.0f, 1.0f, color, 0.0f, 0.0f}, 
		{ (float)(x + width), (float)y           , 0.0f, 1.0f, color, 1.0f, 0.0f},
		{ (float)x          , (float)(y + height), 0.0f, 1.0f, color, 0.0f, 1.0f},
		{ (float)(x + width), (float)(y + height), 0.0f, 1.0f, color, 1.0f, 1.0f}
	};

	LPDIRECT3DDEVICE9 pD3Ddevice = MainThread::GetDevice();
	IDirect3DVertexBuffer9* pVertex = MainThread::GetVertex();
	void* pData;
	
	pVertex->Lock(0, sizeof(MainThread::CUSTOMVERTEX)*4, (void**)&pData, 0);
	memcpy(pData, v, sizeof(MainThread::CUSTOMVERTEX)*4);
	pVertex->Unlock();

	pD3Ddevice->SetTexture(0, NULL);
	pD3Ddevice->SetStreamSource(0, pVertex, 0, sizeof(MainThread::CUSTOMVERTEX));
	pD3Ddevice->SetFVF(MainThread::FVF_CUSTOM);
	pD3Ddevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}