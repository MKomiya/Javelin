#include "LuaStatement.h"
#include "Javelin_glue.h"

LuaStatement::LuaStatement(void) :
	L(NULL)
{
	L = lua_open();
	luaL_openlibs(L);
	tolua_Javelin_open(L);
}

LuaStatement::~LuaStatement(void)
{
	lua_close(L);
}

bool LuaStatement::DoLuaFile(const char* path)
{
	if( luaL_loadfile(L, path) || 
		lua_pcall(L, 0, 0, 0) )
	{
		MessageBox(NULL, lua_tostring(L, -1), "Luaƒtƒ@ƒCƒ‹", MB_OK);
		return false;
	}

	return true;
}