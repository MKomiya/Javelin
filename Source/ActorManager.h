#pragma once
#include "stdafx.h"

class LuaActor;

class ActorManager
{
private:
	hash_map<string, LuaActor*> actorMap;

public:
	ActorManager(void);
	~ActorManager(void);
	
	static ActorManager* GetInst()
	{
		static ActorManager instance;
		return &instance;
	}
};