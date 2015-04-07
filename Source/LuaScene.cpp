#include "LuaScene.h"
#include "LuaStatement.h"

LuaScene::LuaScene(LuaStatement* Ls, string scene_name) :
	Ls(Ls),
	scene_name(scene_name)
{
}

void LuaScene::OnStart()
{
	string func_name = scene_name + "_OnStart";
	string str;
	lua_getglobal(Ls->GetLuaState(), func_name.c_str());
	if( lua_pcall(Ls->GetLuaState(), 0, 0, 0) )
	{
		str = lua_tostring(Ls->GetLuaState(), -1); str += "\n\nリロードしますか？";
		switch( MessageBox(NULL, str.c_str(), func_name.c_str(), MB_YESNO | MB_ICONERROR) )
		{
		case IDYES:
			Ls->DoLuaFile("LuaScript/reload.lua");
			break;
		case IDNO:
			throw "終了します。";
			break;
		}
		return ;
	}
}

void LuaScene::OnFrame()
{
	string func_name = scene_name + "_OnFrame";
	string str;
	lua_getglobal(Ls->GetLuaState(), func_name.c_str());
	if( lua_pcall(Ls->GetLuaState(), 0, 0, 0) )
	{
		str = lua_tostring(Ls->GetLuaState(), -1); str += "\n\nリロードしますか？";
		switch( MessageBox(NULL, str.c_str(), func_name.c_str(), MB_YESNO | MB_ICONERROR) )
		{
		case IDYES:
			Ls->DoLuaFile("LuaScript/reload.lua");
			break;
		case IDNO:
			throw "終了します。";
			break;
		}
		return ;
	}
}

void LuaScene::OnDraw()
{
	string func_name = scene_name + "_OnDraw";
	string str;
	lua_getglobal(Ls->GetLuaState(), func_name.c_str());
	if( lua_pcall(Ls->GetLuaState(), 0, 0, 0) )
	{
		str = lua_tostring(Ls->GetLuaState(), -1); str += "\n\nリロードしますか？";
		switch( MessageBox(NULL, str.c_str(), func_name.c_str(), MB_YESNO | MB_ICONERROR) )
		{
		case IDYES:
			Ls->DoLuaFile("LuaScript/reload.lua");
			break;
		case IDNO:
			throw "終了します。";
			break;
		}
		return ;
	}
}

void LuaScene::OnClose()
{
	string func_name = scene_name + "_OnClose";
	string str;
	lua_getglobal(Ls->GetLuaState(), func_name.c_str());
	if( lua_pcall(Ls->GetLuaState(), 0, 0, 0) )
	{
		str = lua_tostring(Ls->GetLuaState(), -1); str += "\n\nリロードしますか？";
		switch( MessageBox(NULL, str.c_str(), func_name.c_str(), MB_YESNO | MB_ICONERROR) )
		{
		case IDYES:
			Ls->DoLuaFile("LuaScript/reload.lua");
			break;
		case IDNO:
			throw "終了します。";
			break;
		}
		return ;
	}
}