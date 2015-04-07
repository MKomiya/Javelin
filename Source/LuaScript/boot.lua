T = {}
A = {}

-- ゲームの初期化処理
-- ウィンドウを生成し、DirectXを初期化した後、一度だけ実行されます
function InitGame()
end

-- ゲームの終了処理
function OnShutdown()
end

--------------------------------------------------------
-- 以下bootシーン定義
--------------------------------------------------------
function boot_OnStart()
	T.kyoko = Texture("g/kyoko.jpg");
	A.act = Actor(T.kyoko, 100, 0, "kyoko");

	txt = DxFont(12)
	cnt = 0
end

function boot_OnFrame()
	if cnt == 300 then
		
	end
	cnt = cnt + 1

	if MainThread:GetInput():IsKeyPressed( DIK_F2 ) then
		MainThread:GetLs():DoLuaFile("LuaScript/reload.lua");
	end
end

function boot_OnDraw()
	txt:Draw("Count:"..cnt.." / 300", 0, 0)
end

function boot_OnClose()
end

function kyoko_OnStart()
end

function kyoko_OnFrame()
end

function kyoko_OnVanish()
end