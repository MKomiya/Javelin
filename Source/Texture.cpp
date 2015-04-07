#include "Texture.h"  
#include "MainThread.h"

Texture::Texture()  
{  
    texture = NULL;  
}  
  
Texture::Texture(const char* filename)  
{  
    texture = NULL;  
    Load(filename);  
}  
  
Texture::~Texture()  
{  
    RELEASE(texture);  
}  
  
void Texture::GetTextureSize(int *width, int *height)  
{  
    *width = texwidth;  
    *height = texheight;  
}  

void Texture::GetGraphicSize(int *width, int *height)  
{  
    *width = grawidth;  
    *height = graheight;  
}
  
BOOL Texture::Load(const char* filename)  
{  
	D3DXIMAGE_INFO info;

    RELEASE(texture);
    BOOL b = SUCCEEDED( D3DXCreateTextureFromFileEx(MainThread::GetDevice(), filename,
		0, 0, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, 
		D3DX_FILTER_NONE, D3DX_DEFAULT, 0, &info, NULL, &texture) );  

    if(b == TRUE){  
        D3DSURFACE_DESC desc;
  
        // 最上位のテクスチャ情報を取得  
        texture->GetLevelDesc(0, &desc);  
  
        texwidth = (int)desc.Width;  
        texheight = (int)desc.Height;

		grawidth = (int)info.Width;
		graheight = (int)info.Height;
    }  
  
    return b;  
}  