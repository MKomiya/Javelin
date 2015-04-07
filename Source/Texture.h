#pragma once
#include "stdafx.h"

class Texture
{
private:
    // テクスチャを格納するインタフェイス  
    LPDIRECT3DTEXTURE9 texture;  
    int texwidth, texheight;
	int grawidth, graheight;

public:  
    Texture();  
    Texture(const char* filename);  
    ~Texture();  
  
    // 画像ファイルからテクスチャを作成する  
    BOOL Load(const char* filename);  
  
    // テクスチャサイズの取得  
    void GetTextureSize(int *width, int *height);

	// グラフィックそのもののサイズの取得
	void GetGraphicSize(int *width, int *height);
  
    // テクスチャデータを直接取得する  
    const LPDIRECT3DTEXTURE9 GetTexture(){ return texture; }
};

