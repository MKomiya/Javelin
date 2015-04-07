#include "Actor.h"
#include "LuaStatement.h"
#include "MainThread.h"
#include "Sprite.h"

Actor::Actor(Texture* tex, float x, float y, string actor_name, bool drawflg) :
	x(x), y(y),
	drawflg(drawflg),
	actor_name(actor_name),
	sp(new Sprite(tex))
{
	MainThread::AddActor(this);
}

Actor::~Actor(void)
{
	delete sp;
}

void Actor::OnStart()
{
	LuaStatement* Ls = MainThread::GetLs();
	string func_name = actor_name + "_OnStart";
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
			Ls->~LuaStatement();
			throw "終了します。";
			break;
		}
		return ;
	}
}

void Actor::OnFrame()
{
	LuaStatement* Ls = MainThread::GetLs();
	string func_name = actor_name + "_OnFrame";
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
			Ls->~LuaStatement();
			throw "終了します。";
			break;
		}
		return ;
	}
}

void Actor::OnDraw()
{
	if( drawflg )
	{
		LuaStatement* Ls = MainThread::GetLs();
		string func_name = actor_name + "_OnDraw";
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
				Ls->~LuaStatement();
				throw "終了します。";
				break;
			}
			return ;
		}
	}
	else
	{
		sp->Draw(x, y);
	}
}

void Actor::OnVanish()
{
	LuaStatement* Ls = MainThread::GetLs();
	string func_name = actor_name + "_OnVanish";
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
			Ls->~LuaStatement();
			throw "終了します。";
			break;
		}
		return ;
	}
}