/**
 * stdafx.h
 * プリコンパイル済みヘッダー
 */
#include <tchar.h>
#include <windows.h>

#include <list>
#include <string>
using namespace std;

#include <hash_map>
using namespace stdext;

#include <DxErr.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dxdiag.h>

#if _DEBUG  
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>  
#define new  ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )  
#endif

#define RELEASE(x) {if(x) x->Release();}

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"DxErr.lib")
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")

#include <lua.hpp>
#include <tolua++.h>

#pragma comment(lib,"lua51.lib")