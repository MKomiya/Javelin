/**
 * メインスレッドの処理をまとめ、Win32APIを意識しない部分をまとめたクラス
 * DirectX関係の初期化もここで行なっている
 * 処理詰め過ぎとか言うな
 * 静的メンバ大杉とか言うな
 */
#pragma once
#include "stdafx.h"

class Input;
class LuaStatement;
class LuaScene;
class Actor;

class MainThread
{
// 頂点データ関係
public:
	static const DWORD FVF_CUSTOM = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;
	static struct CUSTOMVERTEX
	{
		float x, y, z;	//!< @brief 頂点座標
		float rhw;		//!< @brief 除算数
		D3DCOLOR color;	//!< @brief 頂点カラー
		float u, v;		//!< @brief テクスチャ座標
	};

// ウィンドウとインスタンスのハンドル
private:
	static HWND hWnd;
	static HINSTANCE hInstance;
public:
	static const HWND GetHWnd() { return hWnd; }
	static const HINSTANCE GetHInstance(){ return hInstance; }

// DirectX共通ポインタ群
private:
	static LPDIRECT3D9 pD3D;
	static LPDIRECT3DDEVICE9 pD3Ddevice;
	static IDirect3DVertexBuffer9 *pVertex;
	static ID3DXLine *pLine;
public:
	static LPDIRECT3D9 GetD3D() { return pD3D; }
	static LPDIRECT3DDEVICE9 GetDevice() { return pD3Ddevice; }
	static IDirect3DVertexBuffer9* GetVertex() { return pVertex; }
	static ID3DXLine* GetLine() { return pLine; }

private:
	bool request_quit;
	DWORD lasttime;

// DirectInput8ラッパー関係
private:
	static Input* pInput;
public:
	static Input* GetInput() { return pInput; }

// Lua関係
private:
	static LuaStatement* Ls;
public:
	static LuaStatement* GetLs() { return Ls; }

private:
	static hash_map<string, LuaScene*> sceneMap;
	static string now_scene;
	static list<Actor*> actorList;
	static bool it_moved;
	static list<Actor*>::iterator it_task;

public:
	static LuaScene* AddScene(string scene_name);
	static void ChangeScene(string next_scene);
	static LuaScene* FindScene(string scene_name);

	static void AddActor(Actor* actor);
	static void DeleteActor(string actor_name);
	static void DeleteActorAll();

// メインの処理群
public:
	MainThread(HWND hWnd, HINSTANCE hInstance);

	void Run();

	void InitDirectX();
	void InitGame();

	void BeginFrame();
	void ProcessFrame();
	void DrawFrame();
	void EndFrame();

	void EndGame();
	void ReleaseDirectX();
};

