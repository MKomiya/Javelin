#pragma once
#include "stdafx.h"

class LuaStatement;

class LuaScene
{
private:
	LuaStatement* Ls;
	string scene_name;

public:
	LuaScene(LuaStatement* Ls, string scene_name);

	void OnStart();
	void OnFrame();
	void OnDraw();
	void OnClose();

	string GetSceneName() { return scene_name; }
};

