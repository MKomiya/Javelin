#include "DxFont.h"
#include "MainThread.h"

DxFont::DxFont()
{
	font = NULL;
	Create(16);
}

DxFont::DxFont(int fontsize)
{
 	font = NULL;
	Create(fontsize);
}

DxFont::~DxFont()
{
	RELEASE(font);
}

BOOL DxFont::Create(int fontsize)
{
	RELEASE(font);

	int result = D3DXCreateFont(
		MainThread::GetDevice(),		// 取得元となるデバイス
		fontsize,						// 幅
		NULL,							// 高さ（規定の高さ）
		FW_DONTCARE,					// 太さ（規定の太さ）
		NULL,							// ミップマップレベル（なし）
		FALSE,							// 斜体（なし）
		SHIFTJIS_CHARSET,				// 文字セット（Shift-JIS）
		OUT_DEFAULT_PRECIS,				// 出力精度（標準）
		DEFAULT_QUALITY,				// 出力品質（標準）
		DEFAULT_PITCH | FF_DONTCARE,	// フォントピッチ&フォントファミリ（システムに任せる）
		"MS UI Gothic",					// フォント名
		&font							// 格納先
	);

	return (result == 0) ? FALSE : TRUE;
}

const LPD3DXFONT DxFont::GetD3DXFont()
{
	return font;
}

void DxFont::Draw
	(const char* text, int count, LPRECT pRect,
	DWORD Format, D3DXCOLOR Color)
{
    if(font)
	{
        font->DrawText(NULL, text, count, pRect, Format, Color);
    }
}

void DxFont::Draw(const char* text, int x, int y)
{
	// 最低限の指定だけですむものぐさ版
	// [x, y]の位置を左上にして文字列が描画される
	RECT rect = {x, y, x, y};
	Draw(text, -1, &rect,
		DT_NOCLIP | DT_SINGLELINE,
		0xFFFFFFFF);
}