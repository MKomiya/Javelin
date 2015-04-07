#pragma once
#include "stdafx.h"

class LuaStatement
{
private:
	lua_State* L;

public:
	LuaStatement(void);
	~LuaStatement(void);

	lua_State* GetLuaState() { return L; }
	bool DoLuaFile(const char* path);
};

