#pragma once
#include "gameobject.h"
#include "Sound.h"

class DxFont;
class Texture;
class Sprite;
class BGMusic;
class Input;

class TestScene :
	public GameObject
{
private:
	DxFont* font;
	Texture* tex;
	Sprite* sprite;
	BGMusic* bgm;
	Input* input;
	Sound sound;
	float r;

public:
	TestScene(void);
	~TestScene(void);

public:
	void Init();
	void Exec();
};

