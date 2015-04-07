#pragma once
#include "stdafx.h"

class Figure
{
public:
	Figure(void);
	~Figure(void);

	void DrawLine(int x1, int y1, int x2, int y2, unsigned long color);
	void DrawBox(int x, int y, int width, int height, unsigned long color);
	void DrawFillBox(int x, int y, int width, int height, unsigned long color);
};

