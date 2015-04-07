#pragma once
#include "stdafx.h"

class DxFont
{
private:
	LPD3DXFONT font;

public:
	DxFont();
	DxFont(int fontsize);
	~DxFont();

	BOOL Create(int fontsize);

	void Draw(const char* text, int x, int y);
	void Draw(const char* text, int count, 
		LPRECT pRect, DWORD Format, D3DXCOLOR Color);

	const LPD3DXFONT GetD3DXFont();
};
