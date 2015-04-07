#pragma once
#include "stdafx.h"

class Texture
{
private:
    // �e�N�X�`�����i�[����C���^�t�F�C�X  
    LPDIRECT3DTEXTURE9 texture;  
    int texwidth, texheight;
	int grawidth, graheight;

public:  
    Texture();  
    Texture(const char* filename);  
    ~Texture();  
  
    // �摜�t�@�C������e�N�X�`�����쐬����  
    BOOL Load(const char* filename);  
  
    // �e�N�X�`���T�C�Y�̎擾  
    void GetTextureSize(int *width, int *height);

	// �O���t�B�b�N���̂��̂̃T�C�Y�̎擾
	void GetGraphicSize(int *width, int *height);
  
    // �e�N�X�`���f�[�^�𒼐ڎ擾����  
    const LPDIRECT3DTEXTURE9 GetTexture(){ return texture; }
};

