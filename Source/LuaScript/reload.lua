local files = {}

files = {
	--"LuaScript/testActor.lua",
	--"LuaScript/act2.lua",
	--"LuaScript/testScene.lua",
	"LuaScript/boot.lua",
}

-- �t�@�C�������[�h����
for i,path in ipairs(files) do
	local res = MainThread:GetLs():DoLuaFile(path)
end

InitGame();

boot_OnStart();

return true, "success"