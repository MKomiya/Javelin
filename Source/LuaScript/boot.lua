T = {}
A = {}

-- �Q�[���̏���������
-- �E�B���h�E�𐶐����ADirectX��������������A��x�������s����܂�
function InitGame()
end

-- �Q�[���̏I������
function OnShutdown()
end

--------------------------------------------------------
-- �ȉ�boot�V�[����`
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