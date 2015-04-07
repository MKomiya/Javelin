#pragma once
#include "stdafx.h"

class Sprite;
class Texture;

class Actor
{
private:
	float x, y;
	bool drawflg;
	string actor_name;
	Sprite* sp;

public:
	Actor(Texture* tex, float x, float y, string actor_name, bool drawflg=false);
	~Actor(void);

	void OnStart();
	void OnFrame();
	void OnDraw();
	void OnVanish();

	string GetActorName() { return actor_name; }
	float GetX() { return x; }
	float GetY() { return y; }
	void SetX(float value) { x = value; }
	void SetY(float value) { y = value; }
};