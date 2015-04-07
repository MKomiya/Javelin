/*
** Lua binding: Javelin
** Generated automatically by tolua++-1.0.92-senMod on 03/27/12 00:39:02.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_Javelin_open (lua_State* tolua_S);

#include "stdafx.h"
#include "MainThread.h"
#include "LuaStatement.h"
#include "Actor.h"
#include "Texture.h"
#include "Sprite.h"
#include "DxFont.h"
#include "BGMusic.h"
#include "Input.h"
#include "Figure.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Actor (lua_State* tolua_S)
{
 Actor* self = (Actor*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_BOOL (lua_State* tolua_S)
{
 BOOL* self = (BOOL*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_BYTE (lua_State* tolua_S)
{
 BYTE* self = (BYTE*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_DxFont (lua_State* tolua_S)
{
 DxFont* self = (DxFont*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Sprite (lua_State* tolua_S)
{
 Sprite* self = (Sprite*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_BGMusic (lua_State* tolua_S)
{
 BGMusic* self = (BGMusic*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Figure (lua_State* tolua_S)
{
 Figure* self = (Figure*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_Texture (lua_State* tolua_S)
{
 Texture* self = (Texture*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}

static int tolua_collect_LPDIRECT3DTEXTURE9 (lua_State* tolua_S)
{
 LPDIRECT3DTEXTURE9* self = (LPDIRECT3DTEXTURE9*) tolua_tousertype(tolua_S,1,0);
 delete self;
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Actor");
 tolua_usertype(tolua_S,"BOOL");
 tolua_usertype(tolua_S,"BYTE");
 tolua_usertype(tolua_S,"DxFont");
 tolua_usertype(tolua_S,"Sprite");
 tolua_usertype(tolua_S,"BGMusic");
 tolua_usertype(tolua_S,"Texture");
 tolua_usertype(tolua_S,"Figure");
 tolua_usertype(tolua_S,"Input");
 tolua_usertype(tolua_S,"LPDIRECT3DTEXTURE9");
 tolua_usertype(tolua_S,"MainThread");
 tolua_usertype(tolua_S,"LuaStatement");
}

/* method: GetInput of class  MainThread */
#ifndef TOLUA_DISABLE_tolua_Javelin_MainThread_GetInput00
static int tolua_Javelin_MainThread_GetInput00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MainThread",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Input* tolua_ret = (Input*)  MainThread::GetInput();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Input");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInput'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLs of class  MainThread */
#ifndef TOLUA_DISABLE_tolua_Javelin_MainThread_GetLs00
static int tolua_Javelin_MainThread_GetLs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MainThread",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  LuaStatement* tolua_ret = (LuaStatement*)  MainThread::GetLs();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaStatement");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddScene of class  MainThread */
#ifndef TOLUA_DISABLE_tolua_Javelin_MainThread_AddScene00
static int tolua_Javelin_MainThread_AddScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MainThread",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  string scene_name = ((string)  tolua_tocppstring(tolua_S,2,""));
 {
  MainThread::AddScene(scene_name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChangeScene of class  MainThread */
#ifndef TOLUA_DISABLE_tolua_Javelin_MainThread_ChangeScene00
static int tolua_Javelin_MainThread_ChangeScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MainThread",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  string next_scene = ((string)  tolua_tocppstring(tolua_S,2,""));
 {
  MainThread::ChangeScene(next_scene);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChangeScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddActor of class  MainThread */
#ifndef TOLUA_DISABLE_tolua_Javelin_MainThread_AddActor00
static int tolua_Javelin_MainThread_AddActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MainThread",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Actor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Actor* actor = ((Actor*)  tolua_tousertype(tolua_S,2,0));
 {
  MainThread::AddActor(actor);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteActor of class  MainThread */
#ifndef TOLUA_DISABLE_tolua_Javelin_MainThread_DeleteActor00
static int tolua_Javelin_MainThread_DeleteActor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MainThread",0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  string actor_name = ((string)  tolua_tocppstring(tolua_S,2,""));
 {
  MainThread::DeleteActor(actor_name);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteActor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteActorAll of class  MainThread */
#ifndef TOLUA_DISABLE_tolua_Javelin_MainThread_DeleteActorAll00
static int tolua_Javelin_MainThread_DeleteActorAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"MainThread",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  MainThread::DeleteActorAll();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteActorAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Actor */
#ifndef TOLUA_DISABLE_tolua_Javelin_Actor_new00
static int tolua_Javelin_Actor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Actor",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* tex = ((Texture*)  tolua_tousertype(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  string actor_name = ((string)  tolua_tocppstring(tolua_S,5,""));
  bool drawflg = ((bool)  tolua_toboolean(tolua_S,6,false));
 {
  Actor* tolua_ret = (Actor*)  new Actor(tex,x,y,actor_name,drawflg);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Actor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Actor */
#ifndef TOLUA_DISABLE_tolua_Javelin_Actor_new00_local
static int tolua_Javelin_Actor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Actor",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_iscppstring(tolua_S,5,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* tex = ((Texture*)  tolua_tousertype(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  string actor_name = ((string)  tolua_tocppstring(tolua_S,5,""));
  bool drawflg = ((bool)  tolua_toboolean(tolua_S,6,false));
 {
  Actor* tolua_ret = (Actor*)  new Actor(tex,x,y,actor_name,drawflg);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Actor");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetX of class  Actor */
#ifndef TOLUA_DISABLE_tolua_Javelin_Actor_GetX00
static int tolua_Javelin_Actor_GetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetX'",NULL);
#endif
 {
  float tolua_ret = (float)  self->GetX();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetY of class  Actor */
#ifndef TOLUA_DISABLE_tolua_Javelin_Actor_GetY00
static int tolua_Javelin_Actor_GetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetY'",NULL);
#endif
 {
  float tolua_ret = (float)  self->GetY();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetX of class  Actor */
#ifndef TOLUA_DISABLE_tolua_Javelin_Actor_SetX00
static int tolua_Javelin_Actor_SetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetX'",NULL);
#endif
 {
  self->SetX(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetY of class  Actor */
#ifndef TOLUA_DISABLE_tolua_Javelin_Actor_SetY00
static int tolua_Javelin_Actor_SetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Actor",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Actor* self = (Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetY'",NULL);
#endif
 {
  self->SetY(value);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DoLuaFile of class  LuaStatement */
#ifndef TOLUA_DISABLE_tolua_Javelin_LuaStatement_DoLuaFile00
static int tolua_Javelin_LuaStatement_DoLuaFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"LuaStatement",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  LuaStatement* self = (LuaStatement*)  tolua_tousertype(tolua_S,1,0);
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DoLuaFile'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->DoLuaFile(path);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DoLuaFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_new00
static int tolua_Javelin_Texture_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Texture* tolua_ret = (Texture*)  new Texture();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_new00_local
static int tolua_Javelin_Texture_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Texture* tolua_ret = (Texture*)  new Texture();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Texture");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_new01
static int tolua_Javelin_Texture_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  Texture* tolua_ret = (Texture*)  new Texture(filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Texture");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_Texture_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_new01_local
static int tolua_Javelin_Texture_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  Texture* tolua_ret = (Texture*)  new Texture(filename);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Texture");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_Texture_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_delete00
static int tolua_Javelin_Texture_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_Load00
static int tolua_Javelin_Texture_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'",NULL);
#endif
 {
  BOOL tolua_ret = (BOOL)  self->Load(filename);
 {
#ifdef __cplusplus
 void* tolua_obj = new BOOL(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"BOOL");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(BOOL));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"BOOL");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTextureSize of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_GetTextureSize00
static int tolua_Javelin_Texture_GetTextureSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTextureSize'",NULL);
#endif
 {
  self->GetTextureSize(&width,&height);
 tolua_pushnumber(tolua_S,(lua_Number)width);
 tolua_pushnumber(tolua_S,(lua_Number)height);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTextureSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGraphicSize of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_GetGraphicSize00
static int tolua_Javelin_Texture_GetGraphicSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGraphicSize'",NULL);
#endif
 {
  self->GetGraphicSize(&width,&height);
 tolua_pushnumber(tolua_S,(lua_Number)width);
 tolua_pushnumber(tolua_S,(lua_Number)height);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGraphicSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTexture of class  Texture */
#ifndef TOLUA_DISABLE_tolua_Javelin_Texture_GetTexture00
static int tolua_Javelin_Texture_GetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Texture* self = (Texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTexture'",NULL);
#endif
 {
  const LPDIRECT3DTEXTURE9 tolua_ret = (const LPDIRECT3DTEXTURE9)  self->GetTexture();
 {
#ifdef __cplusplus
 void* tolua_obj = new LPDIRECT3DTEXTURE9(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"const LPDIRECT3DTEXTURE9");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const LPDIRECT3DTEXTURE9));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"const LPDIRECT3DTEXTURE9");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_new00
static int tolua_Javelin_Sprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_new00_local
static int tolua_Javelin_Sprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Sprite");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_new01
static int tolua_Javelin_Sprite_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Texture* source = ((Texture*)  tolua_tousertype(tolua_S,2,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(source);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_Sprite_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_new01_local
static int tolua_Javelin_Sprite_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  Texture* source = ((Texture*)  tolua_tousertype(tolua_S,2,0));
 {
  Sprite* tolua_ret = (Sprite*)  new Sprite(source);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Sprite");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_Sprite_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTexture of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_SetTexture00
static int tolua_Javelin_Sprite_SetTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"Texture",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  Texture* source = ((Texture*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTexture'",NULL);
#endif
 {
  self->SetTexture(source);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCenterPosition of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_SetCenterPosition00
static int tolua_Javelin_Sprite_SetCenterPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  unsigned char pos = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCenterPosition'",NULL);
#endif
 {
  self->SetCenterPosition(pos);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCenterPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCenterPosition of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_GetCenterPosition00
static int tolua_Javelin_Sprite_GetCenterPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCenterPosition'",NULL);
#endif
 {
  BYTE tolua_ret = (BYTE)  self->GetCenterPosition();
 {
#ifdef __cplusplus
 void* tolua_obj = new BYTE(tolua_ret);
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"BYTE");
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(BYTE));
 tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"BYTE");
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCenterPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSpriteSize of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_GetSpriteSize00
static int tolua_Javelin_Sprite_GetSpriteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSpriteSize'",NULL);
#endif
 {
  self->GetSpriteSize(&width,&height);
 tolua_pushnumber(tolua_S,(lua_Number)width);
 tolua_pushnumber(tolua_S,(lua_Number)height);
 }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSpriteSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSpriteSize of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_SetSpriteSize00
static int tolua_Javelin_Sprite_SetSpriteSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  int width = ((int)  tolua_tonumber(tolua_S,2,0));
  int height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSpriteSize'",NULL);
#endif
 {
  self->SetSpriteSize(width,height);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSpriteSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSpriteRect of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_SetSpriteRect00
static int tolua_Javelin_Sprite_SetSpriteRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  int left = ((int)  tolua_tonumber(tolua_S,2,0));
  int top = ((int)  tolua_tonumber(tolua_S,3,0));
  int right = ((int)  tolua_tonumber(tolua_S,4,0));
  int bottom = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSpriteRect'",NULL);
#endif
 {
  self->SetSpriteRect(left,top,right,bottom);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSpriteRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFrame of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_SetFrame00
static int tolua_Javelin_Sprite_SetFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  int frame = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFrame'",NULL);
#endif
 {
  self->SetFrame(frame);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Draw of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_Draw00
static int tolua_Javelin_Sprite_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  int alpha = ((int)  tolua_tonumber(tolua_S,4,255));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Draw'",NULL);
#endif
 {
  self->Draw(x,y,alpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawRot of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_DrawRot00
static int tolua_Javelin_Sprite_DrawRot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float r = ((float)  tolua_tonumber(tolua_S,4,0));
  int alpha = ((int)  tolua_tonumber(tolua_S,5,255));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawRot'",NULL);
#endif
 {
  self->DrawRot(x,y,r,alpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawRot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawExt of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_DrawExt00
static int tolua_Javelin_Sprite_DrawExt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float ex = ((float)  tolua_tonumber(tolua_S,4,0));
  float ey = ((float)  tolua_tonumber(tolua_S,5,0));
  int alpha = ((int)  tolua_tonumber(tolua_S,6,255));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawExt'",NULL);
#endif
 {
  self->DrawExt(x,y,ex,ey,alpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawExt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawExtRot of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_DrawExtRot00
static int tolua_Javelin_Sprite_DrawExtRot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,7,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float ex = ((float)  tolua_tonumber(tolua_S,4,0));
  float ey = ((float)  tolua_tonumber(tolua_S,5,0));
  float r = ((float)  tolua_tonumber(tolua_S,6,0));
  int alpha = ((int)  tolua_tonumber(tolua_S,7,255));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawExtRot'",NULL);
#endif
 {
  self->DrawExtRot(x,y,ex,ey,r,alpha);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawExtRot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBlendMode of class  Sprite */
#ifndef TOLUA_DISABLE_tolua_Javelin_Sprite_SetBlendMode00
static int tolua_Javelin_Sprite_SetBlendMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Sprite",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Sprite* self = (Sprite*)  tolua_tousertype(tolua_S,1,0);
  int mode = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBlendMode'",NULL);
#endif
 {
  self->SetBlendMode(mode);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBlendMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  DxFont */
#ifndef TOLUA_DISABLE_tolua_Javelin_DxFont_new00
static int tolua_Javelin_DxFont_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DxFont",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  DxFont* tolua_ret = (DxFont*)  new DxFont();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"DxFont");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  DxFont */
#ifndef TOLUA_DISABLE_tolua_Javelin_DxFont_new00_local
static int tolua_Javelin_DxFont_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DxFont",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  DxFont* tolua_ret = (DxFont*)  new DxFont();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"DxFont");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  DxFont */
#ifndef TOLUA_DISABLE_tolua_Javelin_DxFont_new01
static int tolua_Javelin_DxFont_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DxFont",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int fontsize = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  DxFont* tolua_ret = (DxFont*)  new DxFont(fontsize);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"DxFont");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_DxFont_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  DxFont */
#ifndef TOLUA_DISABLE_tolua_Javelin_DxFont_new01_local
static int tolua_Javelin_DxFont_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"DxFont",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  int fontsize = ((int)  tolua_tonumber(tolua_S,2,0));
 {
  DxFont* tolua_ret = (DxFont*)  new DxFont(fontsize);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"DxFont");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_DxFont_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  DxFont */
#ifndef TOLUA_DISABLE_tolua_Javelin_DxFont_delete00
static int tolua_Javelin_DxFont_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DxFont",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DxFont* self = (DxFont*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Draw of class  DxFont */
#ifndef TOLUA_DISABLE_tolua_Javelin_DxFont_Draw00
static int tolua_Javelin_DxFont_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DxFont",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DxFont* self = (DxFont*)  tolua_tousertype(tolua_S,1,0);
  const char* text = ((const char*)  tolua_tostring(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Draw'",NULL);
#endif
 {
  self->Draw(text,x,y);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Figure */
#ifndef TOLUA_DISABLE_tolua_Javelin_Figure_new00
static int tolua_Javelin_Figure_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Figure",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Figure* tolua_ret = (Figure*)  new Figure();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"Figure");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Figure */
#ifndef TOLUA_DISABLE_tolua_Javelin_Figure_new00_local
static int tolua_Javelin_Figure_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"Figure",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Figure* tolua_ret = (Figure*)  new Figure();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"Figure");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Figure */
#ifndef TOLUA_DISABLE_tolua_Javelin_Figure_delete00
static int tolua_Javelin_Figure_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Figure",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Figure* self = (Figure*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawLine of class  Figure */
#ifndef TOLUA_DISABLE_tolua_Javelin_Figure_DrawLine00
static int tolua_Javelin_Figure_DrawLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Figure",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Figure* self = (Figure*)  tolua_tousertype(tolua_S,1,0);
  int x1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,5,0));
  unsigned long color = ((unsigned long)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawLine'",NULL);
#endif
 {
  self->DrawLine(x1,y1,x2,y2,color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawBox of class  Figure */
#ifndef TOLUA_DISABLE_tolua_Javelin_Figure_DrawBox00
static int tolua_Javelin_Figure_DrawBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Figure",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Figure* self = (Figure*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
  unsigned long color = ((unsigned long)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawBox'",NULL);
#endif
 {
  self->DrawBox(x,y,width,height,color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawFillBox of class  Figure */
#ifndef TOLUA_DISABLE_tolua_Javelin_Figure_DrawFillBox00
static int tolua_Javelin_Figure_DrawFillBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Figure",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Figure* self = (Figure*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  int width = ((int)  tolua_tonumber(tolua_S,4,0));
  int height = ((int)  tolua_tonumber(tolua_S,5,0));
  unsigned long color = ((unsigned long)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawFillBox'",NULL);
#endif
 {
  self->DrawFillBox(x,y,width,height,color);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawFillBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsKeyDown of class  Input */
#ifndef TOLUA_DISABLE_tolua_Javelin_Input_IsKeyDown00
static int tolua_Javelin_Input_IsKeyDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsKeyDown'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsKeyDown(key);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsKeyDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsKeyPressed of class  Input */
#ifndef TOLUA_DISABLE_tolua_Javelin_Input_IsKeyPressed00
static int tolua_Javelin_Input_IsKeyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsKeyPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsKeyPressed(key);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsKeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsKeyReleased of class  Input */
#ifndef TOLUA_DISABLE_tolua_Javelin_Input_IsKeyReleased00
static int tolua_Javelin_Input_IsKeyReleased00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int key = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsKeyReleased'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsKeyReleased(key);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsKeyReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPovPosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_Javelin_Input_GetPovPosition00
static int tolua_Javelin_Input_GetPovPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPovPosition'",NULL);
#endif
 {
  unsigned char tolua_ret = (unsigned char)  self->GetPovPosition();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPovPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsButtonDown of class  Input */
#ifndef TOLUA_DISABLE_tolua_Javelin_Input_IsButtonDown00
static int tolua_Javelin_Input_IsButtonDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsButtonDown'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsButtonDown(pos);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsButtonDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsButtonPressed of class  Input */
#ifndef TOLUA_DISABLE_tolua_Javelin_Input_IsButtonPressed00
static int tolua_Javelin_Input_IsButtonPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsButtonPressed'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsButtonPressed(pos);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsButtonPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsButtonReleased of class  Input */
#ifndef TOLUA_DISABLE_tolua_Javelin_Input_IsButtonReleased00
static int tolua_Javelin_Input_IsButtonReleased00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
  int pos = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsButtonReleased'",NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsButtonReleased(pos);
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsButtonReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_new00
static int tolua_Javelin_BGMusic_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BGMusic* tolua_ret = (BGMusic*)  new BGMusic();
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"BGMusic");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_new00_local
static int tolua_Javelin_BGMusic_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  BGMusic* tolua_ret = (BGMusic*)  new BGMusic();
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"BGMusic");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_new01
static int tolua_Javelin_BGMusic_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  BGMusic* tolua_ret = (BGMusic*)  new BGMusic(filename);
 tolua_pushusertype(tolua_S,(void*)tolua_ret,"BGMusic");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_BGMusic_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_new01_local
static int tolua_Javelin_BGMusic_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
 !tolua_isusertable(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
 {
  BGMusic* tolua_ret = (BGMusic*)  new BGMusic(filename);
 tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"BGMusic");
 }
 }
 return 1;
tolua_lerror:
 return tolua_Javelin_BGMusic_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_delete00
static int tolua_Javelin_BGMusic_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BGMusic* self = (BGMusic*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
 delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_Load00
static int tolua_Javelin_BGMusic_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BGMusic* self = (BGMusic*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'",NULL);
#endif
 {
  self->Load(filename);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_Play00
static int tolua_Javelin_BGMusic_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BGMusic* self = (BGMusic*)  tolua_tousertype(tolua_S,1,0);
  bool loop = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'",NULL);
#endif
 {
  self->Play(loop);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_Stop00
static int tolua_Javelin_BGMusic_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BGMusic* self = (BGMusic*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'",NULL);
#endif
 {
  self->Stop();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVolume of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_SetVolume00
static int tolua_Javelin_BGMusic_SetVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BGMusic* self = (BGMusic*)  tolua_tousertype(tolua_S,1,0);
  long volume = ((long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVolume'",NULL);
#endif
 {
  self->SetVolume(volume);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Fade of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_Fade00
static int tolua_Javelin_BGMusic_Fade00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BGMusic* self = (BGMusic*)  tolua_tousertype(tolua_S,1,0);
  unsigned long endtime = ((unsigned long)  tolua_tonumber(tolua_S,2,0));
  long volume = ((long)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Fade'",NULL);
#endif
 {
  self->Fade(endtime,volume);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fade'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  BGMusic */
#ifndef TOLUA_DISABLE_tolua_Javelin_BGMusic_Update00
static int tolua_Javelin_BGMusic_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"BGMusic",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  BGMusic* self = (BGMusic*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'",NULL);
#endif
 {
  self->Update();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Javelin_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_cclass(tolua_S,"MainThread","MainThread","",NULL);
 tolua_beginmodule(tolua_S,"MainThread");
  tolua_function(tolua_S,"GetInput",tolua_Javelin_MainThread_GetInput00);
  tolua_function(tolua_S,"GetLs",tolua_Javelin_MainThread_GetLs00);
  tolua_function(tolua_S,"AddScene",tolua_Javelin_MainThread_AddScene00);
  tolua_function(tolua_S,"ChangeScene",tolua_Javelin_MainThread_ChangeScene00);
  tolua_function(tolua_S,"AddActor",tolua_Javelin_MainThread_AddActor00);
  tolua_function(tolua_S,"DeleteActor",tolua_Javelin_MainThread_DeleteActor00);
  tolua_function(tolua_S,"DeleteActorAll",tolua_Javelin_MainThread_DeleteActorAll00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Actor","Actor","",tolua_collect_Actor);
 #else
 tolua_cclass(tolua_S,"Actor","Actor","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Actor");
  tolua_function(tolua_S,"new",tolua_Javelin_Actor_new00);
  tolua_function(tolua_S,"new_local",tolua_Javelin_Actor_new00_local);
  tolua_function(tolua_S,".call",tolua_Javelin_Actor_new00_local);
  tolua_function(tolua_S,"GetX",tolua_Javelin_Actor_GetX00);
  tolua_function(tolua_S,"GetY",tolua_Javelin_Actor_GetY00);
  tolua_function(tolua_S,"SetX",tolua_Javelin_Actor_SetX00);
  tolua_function(tolua_S,"SetY",tolua_Javelin_Actor_SetY00);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"LuaStatement","LuaStatement","",NULL);
 tolua_beginmodule(tolua_S,"LuaStatement");
  tolua_function(tolua_S,"DoLuaFile",tolua_Javelin_LuaStatement_DoLuaFile00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Texture","Texture","",tolua_collect_Texture);
 #else
 tolua_cclass(tolua_S,"Texture","Texture","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Texture");
  tolua_function(tolua_S,"new",tolua_Javelin_Texture_new00);
  tolua_function(tolua_S,"new_local",tolua_Javelin_Texture_new00_local);
  tolua_function(tolua_S,".call",tolua_Javelin_Texture_new00_local);
  tolua_function(tolua_S,"new",tolua_Javelin_Texture_new01);
  tolua_function(tolua_S,"new_local",tolua_Javelin_Texture_new01_local);
  tolua_function(tolua_S,".call",tolua_Javelin_Texture_new01_local);
  tolua_function(tolua_S,"delete",tolua_Javelin_Texture_delete00);
  tolua_function(tolua_S,"Load",tolua_Javelin_Texture_Load00);
  tolua_function(tolua_S,"GetTextureSize",tolua_Javelin_Texture_GetTextureSize00);
  tolua_function(tolua_S,"GetGraphicSize",tolua_Javelin_Texture_GetGraphicSize00);
  tolua_function(tolua_S,"GetTexture",tolua_Javelin_Texture_GetTexture00);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"CP_MIDDLECENTER",CP_MIDDLECENTER);
 tolua_constant(tolua_S,"CP_LEFT",CP_LEFT);
 tolua_constant(tolua_S,"CP_CENTER",CP_CENTER);
 tolua_constant(tolua_S,"CP_RIGHT",CP_RIGHT);
 tolua_constant(tolua_S,"CP_TOP",CP_TOP);
 tolua_constant(tolua_S,"CP_MIDDLE",CP_MIDDLE);
 tolua_constant(tolua_S,"CP_BOTTOM",CP_BOTTOM);
 tolua_constant(tolua_S,"ALPHA_BLEND",ALPHA_BLEND);
 tolua_constant(tolua_S,"ADD_BLEND",ADD_BLEND);
 tolua_constant(tolua_S,"SUB_BLEND",SUB_BLEND);
 tolua_constant(tolua_S,"MULA_BLEND",MULA_BLEND);
 tolua_constant(tolua_S,"INVS_BLEND",INVS_BLEND);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Sprite","Sprite","",tolua_collect_Sprite);
 #else
 tolua_cclass(tolua_S,"Sprite","Sprite","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Sprite");
  tolua_function(tolua_S,"new",tolua_Javelin_Sprite_new00);
  tolua_function(tolua_S,"new_local",tolua_Javelin_Sprite_new00_local);
  tolua_function(tolua_S,".call",tolua_Javelin_Sprite_new00_local);
  tolua_function(tolua_S,"new",tolua_Javelin_Sprite_new01);
  tolua_function(tolua_S,"new_local",tolua_Javelin_Sprite_new01_local);
  tolua_function(tolua_S,".call",tolua_Javelin_Sprite_new01_local);
  tolua_function(tolua_S,"SetTexture",tolua_Javelin_Sprite_SetTexture00);
  tolua_function(tolua_S,"SetCenterPosition",tolua_Javelin_Sprite_SetCenterPosition00);
  tolua_function(tolua_S,"GetCenterPosition",tolua_Javelin_Sprite_GetCenterPosition00);
  tolua_function(tolua_S,"GetSpriteSize",tolua_Javelin_Sprite_GetSpriteSize00);
  tolua_function(tolua_S,"SetSpriteSize",tolua_Javelin_Sprite_SetSpriteSize00);
  tolua_function(tolua_S,"SetSpriteRect",tolua_Javelin_Sprite_SetSpriteRect00);
  tolua_function(tolua_S,"SetFrame",tolua_Javelin_Sprite_SetFrame00);
  tolua_function(tolua_S,"Draw",tolua_Javelin_Sprite_Draw00);
  tolua_function(tolua_S,"DrawRot",tolua_Javelin_Sprite_DrawRot00);
  tolua_function(tolua_S,"DrawExt",tolua_Javelin_Sprite_DrawExt00);
  tolua_function(tolua_S,"DrawExtRot",tolua_Javelin_Sprite_DrawExtRot00);
  tolua_function(tolua_S,"SetBlendMode",tolua_Javelin_Sprite_SetBlendMode00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"DxFont","DxFont","",tolua_collect_DxFont);
 #else
 tolua_cclass(tolua_S,"DxFont","DxFont","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"DxFont");
  tolua_function(tolua_S,"new",tolua_Javelin_DxFont_new00);
  tolua_function(tolua_S,"new_local",tolua_Javelin_DxFont_new00_local);
  tolua_function(tolua_S,".call",tolua_Javelin_DxFont_new00_local);
  tolua_function(tolua_S,"new",tolua_Javelin_DxFont_new01);
  tolua_function(tolua_S,"new_local",tolua_Javelin_DxFont_new01_local);
  tolua_function(tolua_S,".call",tolua_Javelin_DxFont_new01_local);
  tolua_function(tolua_S,"delete",tolua_Javelin_DxFont_delete00);
  tolua_function(tolua_S,"Draw",tolua_Javelin_DxFont_Draw00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"Figure","Figure","",tolua_collect_Figure);
 #else
 tolua_cclass(tolua_S,"Figure","Figure","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"Figure");
  tolua_function(tolua_S,"new",tolua_Javelin_Figure_new00);
  tolua_function(tolua_S,"new_local",tolua_Javelin_Figure_new00_local);
  tolua_function(tolua_S,".call",tolua_Javelin_Figure_new00_local);
  tolua_function(tolua_S,"delete",tolua_Javelin_Figure_delete00);
  tolua_function(tolua_S,"DrawLine",tolua_Javelin_Figure_DrawLine00);
  tolua_function(tolua_S,"DrawBox",tolua_Javelin_Figure_DrawBox00);
  tolua_function(tolua_S,"DrawFillBox",tolua_Javelin_Figure_DrawFillBox00);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"DIK_UP",DIK_UP);
 tolua_constant(tolua_S,"DIK_LEFT",DIK_LEFT);
 tolua_constant(tolua_S,"DIK_DOWN",DIK_DOWN);
 tolua_constant(tolua_S,"DIK_RIGHT",DIK_RIGHT);
 tolua_constant(tolua_S,"DIK_F2",DIK_F2);
 tolua_constant(tolua_S,"PP_UP",PP_UP);
 tolua_constant(tolua_S,"PP_RIGHT",PP_RIGHT);
 tolua_constant(tolua_S,"PP_DOWN",PP_DOWN);
 tolua_constant(tolua_S,"PP_LEFT",PP_LEFT);
 tolua_cclass(tolua_S,"Input","Input","",NULL);
 tolua_beginmodule(tolua_S,"Input");
  tolua_function(tolua_S,"IsKeyDown",tolua_Javelin_Input_IsKeyDown00);
  tolua_function(tolua_S,"IsKeyPressed",tolua_Javelin_Input_IsKeyPressed00);
  tolua_function(tolua_S,"IsKeyReleased",tolua_Javelin_Input_IsKeyReleased00);
  tolua_function(tolua_S,"GetPovPosition",tolua_Javelin_Input_GetPovPosition00);
  tolua_function(tolua_S,"IsButtonDown",tolua_Javelin_Input_IsButtonDown00);
  tolua_function(tolua_S,"IsButtonPressed",tolua_Javelin_Input_IsButtonPressed00);
  tolua_function(tolua_S,"IsButtonReleased",tolua_Javelin_Input_IsButtonReleased00);
 tolua_endmodule(tolua_S);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"BGMusic","BGMusic","",tolua_collect_BGMusic);
 #else
 tolua_cclass(tolua_S,"BGMusic","BGMusic","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"BGMusic");
  tolua_function(tolua_S,"new",tolua_Javelin_BGMusic_new00);
  tolua_function(tolua_S,"new_local",tolua_Javelin_BGMusic_new00_local);
  tolua_function(tolua_S,".call",tolua_Javelin_BGMusic_new00_local);
  tolua_function(tolua_S,"new",tolua_Javelin_BGMusic_new01);
  tolua_function(tolua_S,"new_local",tolua_Javelin_BGMusic_new01_local);
  tolua_function(tolua_S,".call",tolua_Javelin_BGMusic_new01_local);
  tolua_function(tolua_S,"delete",tolua_Javelin_BGMusic_delete00);
  tolua_function(tolua_S,"Load",tolua_Javelin_BGMusic_Load00);
  tolua_function(tolua_S,"Play",tolua_Javelin_BGMusic_Play00);
  tolua_function(tolua_S,"Stop",tolua_Javelin_BGMusic_Stop00);
  tolua_function(tolua_S,"SetVolume",tolua_Javelin_BGMusic_SetVolume00);
  tolua_function(tolua_S,"Fade",tolua_Javelin_BGMusic_Fade00);
  tolua_function(tolua_S,"Update",tolua_Javelin_BGMusic_Update00);
 tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Javelin (lua_State* tolua_S) {
 return tolua_Javelin_open(tolua_S);
};
#endif

