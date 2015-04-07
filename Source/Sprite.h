#pragma once
#include "stdafx.h"

#define CP_MIDDLECENTER 0  
#define CP_LEFT 1  
#define CP_CENTER 2  
#define CP_RIGHT 4  
#define CP_TOP 8  
#define CP_MIDDLE 16  
#define CP_BOTTOM 32

#define ALPHA_BLEND	0
#define ADD_BLEND	1
#define SUB_BLEND	2
#define MULA_BLEND	3
#define INVS_BLEND	4

class Texture;

class Sprite
{  
private:  
    Texture *texture;

    BYTE cpos;					// ��_�̈ʒu  
    float orig_x, orig_y;		// ���_�̈ʒu  
	int texwidth, texheight;	// �e�N�X�`���̃T�C�Y
      
    int swidth, sheight;		// �X�v���C�g�̃T�C�Y  
	RECT drawrect;				// �]���͈�

    void Reset();
  
public:  
    Sprite();  
    Sprite(Texture *source);  
      
    void SetTexture(Texture *source);

    void SetCenterPosition(unsigned char pos);  
    BYTE GetCenterPosition();

	void GetSpriteSize(int *width, int *height);
	void SetSpriteSize(int width, int height);

	// �t���[���P�ʂł͂Ȃ�����͈̔͂̃O���t�B�b�N��]�������Ƃ��ɂ�
	// SetSpriteRect()�Œ��ڔ͈͂��w��ł���悤�ɂ���
	void SetSpriteRect(int left, int top, int right, int bottom);
    
	void SetFrame(int frame);

    // ���S�s�����̒l���A���t�@�l�̃f�t�H���g�����Ƃ��Ēǉ�  
	void Draw(float x, float y, int alpha = 255);
	void DrawRot(float x, float y, float r, int alpha = 255);
	void DrawExt(float x, float y, float ex, float ey, int alpha = 255);
	void DrawExtRot(float x, float y, float ex, float ey, float r, int alpha = 255);

	void SetBlendMode(int mode);
}; 