#include "Sprite.h"
#include "Texture.h"
#include "MainThread.h"

Sprite::Sprite()
{
	Reset();
}

Sprite::Sprite(Texture *source)
{
	Reset();
	SetTexture(source);
}

void Sprite::Reset()  
{  
    texture = NULL;  
    cpos = CP_MIDDLECENTER;  
	texwidth = 0;
    orig_x = orig_y = 0.0f;
	swidth = sheight = 0;
	SetRect(&drawrect, 0, 0, 0, 0);
}

void Sprite::SetTexture(Texture *source)
{
    if(source == NULL) return;  
    texture = source;  
  
    //texture->GetTextureSize(&swidth, &sheight);  
	texture->GetGraphicSize(&swidth, &sheight);

	texture->GetTextureSize(&texwidth, &texheight);
	SetSpriteSize(swidth, sheight);
}

void Sprite::SetCenterPosition(unsigned char pos)  
{  
    // 原点の位置を計算  
    cpos = pos;  
  
    if(pos & CP_LEFT)
	{  
        orig_x = 0.0f;  
    }
	else if(pos & CP_RIGHT)
	{  
        orig_x = (float)swidth;  
    }
	else
	{  
        orig_x = (float)swidth / 2.0f;  
    }  
  
    if(pos & CP_TOP)
	{  
        orig_y = 0.0f;  
    }
	else if(pos & CP_BOTTOM)
	{  
        orig_y = (float)sheight;  
    }
	else
	{  
        orig_y = (float)sheight / 2.0f;  
    }  
}  
  
BYTE Sprite::GetCenterPosition()  
{  
    return cpos;  
}

void Sprite::SetSpriteSize(int width, int height)
{
	// スプライトのサイズを変更
	swidth = width;
	sheight = height;

	// 原点位置の更新
	SetCenterPosition(cpos);

	// フレームのリセット
	SetFrame(0);
}

void Sprite::GetSpriteSize(int *width, int *height)
{
	*width = swidth;
	*height = sheight;
}

void Sprite::SetSpriteRect(int left, int top, int right, int bottom)
{
	swidth = right - left;
	sheight = bottom - top;

	drawrect.left = left;
	drawrect.right = right;
	drawrect.top = top;
	drawrect.bottom = bottom;

	SetCenterPosition(cpos);
}

void Sprite::SetFrame(int frame)
{
	// 指定したフレーム値より転送範囲を計算
	int d = texwidth / swidth;
	if(d == 0) return;

	int xpos = frame % d;
	int ypos = frame / d;

	drawrect.left = xpos * swidth;
	drawrect.right = drawrect.left + swidth;
	drawrect.top = ypos * sheight;
	drawrect.bottom = drawrect.top + sheight;
}

void Sprite::Draw(float x, float y, int alpha)
{
	DrawExtRot(x, y, 1.0f, 1.0f, 0.0f, alpha);
}

void Sprite::DrawRot(float x, float y, float r, int alpha)
{
	DrawExtRot(x, y, 1.0f, 1.0f, r, alpha);
}

void Sprite::DrawExt(float x, float y, float ex, float ey, int alpha)
{
	DrawExtRot(x, y, ex, ey, 0.0f, alpha);
}

void Sprite::DrawExtRot(float x, float y, float ex, float ey, float r, int alpha)
{
	float tu1, tv1, tu2, tv2;
	tu1 = (float)drawrect.left / (float)texwidth;
	tv1 = (float)drawrect.top / (float)texheight;
	tu2 = (float)drawrect.right / (float)texwidth;
	tv2 = (float)drawrect.bottom / (float)texheight;

	D3DXMATRIX PosMatrix, MoveMatrix, RotateMatrix, ZoomMatrix;
	//MainThread::CUSTOMVERTEX v[4] =
	//{
	//	{ x - texwidth/2.f, y - texheight/2.f, 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu1, tv1}, 
	//	{ x + texwidth/2.f, y - texheight/2.f, 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu2, tv1},
	//	{ x - texwidth/2.f, y + texheight/2.f, 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu1, tv2},
	//	{ x + texwidth/2.f, y + texheight/2.f, 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu2, tv2}
	//};

	MainThread::CUSTOMVERTEX v[4] =
	{
		{ x         , y          , 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu1, tv1}, 
		{ x + swidth, y          , 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu2, tv1},
		{ x         , y + sheight, 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu1, tv2},
		{ x + swidth, y + sheight, 0.0f, 1.0f, D3DCOLOR_ARGB(alpha,255,255,255), tu2, tv2}
	};

	// 拡大行列と合成
	if(ex != 1.0f || ey != 1.0f)
	{
		float x1, y1;
		x1 = v[0].x + swidth / 2.0f;
		y1 = v[0].y + sheight / 2.0f;

		// 移動量設定
		D3DXMatrixTranslation(&MoveMatrix, -x1, -y1, 0.0f);

		// 移動処理
		for ( int i=0 ; i<4 ; i++ )
		{
			// 現在の頂点座標を格納
			D3DXMatrixTranslation(&PosMatrix, v[i].x, v[i].y, v[i].z);
			// 演算
			PosMatrix *= MoveMatrix;
			// 結果を戻す
			v[i].x = PosMatrix._41;
			v[i].y = PosMatrix._42;
			v[i].z = PosMatrix._43;
		}

		D3DXMatrixScaling(&ZoomMatrix, ex, ey, 1.0f);

		for(int i=0; i<4; i++)
		{
			// 現在の頂点座標を格納
			D3DXMatrixTranslation(&PosMatrix, v[i].x, v[i].y, v[i].z);
			//// 演算
			PosMatrix *= ZoomMatrix;
			//// 結果を戻す
			v[i].x = PosMatrix._41;
			v[i].y = PosMatrix._42;
			v[i].z = PosMatrix._43;
		}

		// 移動量設定
		D3DXMatrixTranslation(&MoveMatrix, x1, y1, 0.0f);

		// 移動処理
		for ( int i=0 ; i<4 ; i++ )
		{
			// 現在の頂点座標を格納
			D3DXMatrixTranslation(&PosMatrix, v[i].x, v[i].y, v[i].z);
			// 演算
			PosMatrix *= MoveMatrix;
			// 結果を戻す
			v[i].x = PosMatrix._41;
			v[i].y = PosMatrix._42;
			v[i].z = PosMatrix._43;
		}
	}

	if(r != 0.0f)
	{
		float x1, y1;
		x1 = v[0].x + swidth*ex / 2.0f;
		y1 = v[0].y + sheight*ey / 2.0f;

		// 移動量設定
		D3DXMatrixTranslation(&MoveMatrix, -x1, -y1, 0.0f);

		// 移動処理
		for ( int i=0 ; i<4 ; i++ )
		{
			// 現在の頂点座標を格納
			D3DXMatrixTranslation(&PosMatrix, v[i].x, v[i].y, v[i].z);
			// 演算
			PosMatrix *= MoveMatrix;
			// 結果を戻す
			v[i].x = PosMatrix._41;
			v[i].y = PosMatrix._42;
			v[i].z = PosMatrix._43;
		}

		// 回転行列に角度を設定
		D3DXMatrixRotationZ(&RotateMatrix, r);

		for(int i=0; i<4; i++)
		{
			// 現在の頂点座標を格納
			D3DXMatrixTranslation(&PosMatrix, v[i].x, v[i].y, v[i].z);
			//// 演算
			PosMatrix *= RotateMatrix;
			//// 結果を戻す
			v[i].x = PosMatrix._41;
			v[i].y = PosMatrix._42;
			v[i].z = PosMatrix._43;
		}

		// 移動量設定
		D3DXMatrixTranslation(&MoveMatrix, x1, y1, 0.0f);

		// 移動処理
		for ( int i=0 ; i<4 ; i++ )
		{
			// 現在の頂点座標を格納
			D3DXMatrixTranslation(&PosMatrix, v[i].x, v[i].y, v[i].z);
			// 演算
			PosMatrix *= MoveMatrix;
			// 結果を戻す
			v[i].x = PosMatrix._41;
			v[i].y = PosMatrix._42;
			v[i].z = PosMatrix._43;
		}
	}

	LPDIRECT3DDEVICE9 pD3Ddevice = MainThread::GetDevice();
	IDirect3DVertexBuffer9* pVertex = MainThread::GetVertex();
	void* pData;
	
	pVertex->Lock(0, sizeof(MainThread::CUSTOMVERTEX)*4, (void**)&pData, 0);
	memcpy(pData, v, sizeof(MainThread::CUSTOMVERTEX)*4);
	pVertex->Unlock();

	pD3Ddevice->SetTexture(0, texture->GetTexture());
	pD3Ddevice->SetStreamSource(0, pVertex, 0, sizeof(MainThread::CUSTOMVERTEX));
	pD3Ddevice->SetFVF(MainThread::FVF_CUSTOM);
	pD3Ddevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

void Sprite::SetBlendMode(int mode)
{
	LPDIRECT3DDEVICE9 pD3Ddevice = MainThread::GetDevice();
	DWORD src, dest;

	D3DSURFACE_DESC desc;
	D3DLOCKED_RECT rect;
	BYTE* pPixel;
	
	switch( mode )
	{
	case ALPHA_BLEND:
		src = D3DBLEND_SRCALPHA;
		dest = D3DBLEND_INVSRCALPHA;
		break;
	case ADD_BLEND:
		src = D3DBLEND_ONE;
		dest = D3DBLEND_ONE;
		break;
	case SUB_BLEND:
		src = D3DBLEND_ZERO | D3DBLEND_SRCALPHA;
		dest = D3DBLEND_INVSRCCOLOR;
		pD3Ddevice->SetRenderState( D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT );
		break;
	case MULA_BLEND:
		src = D3DBLEND_ZERO | D3DBLEND_SRCALPHA;
		dest = D3DBLEND_SRCCOLOR;
		pD3Ddevice->SetRenderState( D3DRS_BLENDOP, D3DBLENDOP_ADD );
		break;
	case INVS_BLEND:
		texture->GetTexture()->GetLevelDesc(0, &desc);
		texture->GetTexture()->LockRect(0, &rect, NULL, D3DLOCK_DISCARD);
		pPixel = (BYTE*) rect.pBits;
		for( DWORD i = 0; i < desc.Height; i++ )
		{
			DWORD* pLinePixel = (DWORD*) pPixel;
			for( DWORD k = 0; k < desc.Width; k++ )
			{
				*pLinePixel = *pLinePixel ^ 0xffffff;
				pLinePixel++;
			}
			pPixel += rect.Pitch;
		}
		texture->GetTexture()->UnlockRect(0);
		return ;
	}

	pD3Ddevice->SetRenderState( D3DRS_SRCBLEND,  src );
	pD3Ddevice->SetRenderState( D3DRS_DESTBLEND, dest );
    pD3Ddevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
}