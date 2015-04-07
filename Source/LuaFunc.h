#pragma once
#include <lua.hpp>


class LuaFunc
{
private:
	lua_State* m_L;

public:
	LuaFunc(void);
	~LuaFunc(void);

	void SetLua(lua_State* L);
	bool DoLuaFile(const char* filename);
};

