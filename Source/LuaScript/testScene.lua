function testScene_OnStart()
	tex = Texture("g/anime.png")
	sp = Sprite(tex)
	sp:SetSpriteSize(128, 128)

	count, frame = 0, 0
end

function testScene_OnFrame()
	count = count + 1
	if count >= 12 then
		count = 0
		frame = frame + 1
		if frame >= 8 then
			frame = 0
		end
		sp:SetFrame(frame)
	end
end

function testScene_OnDraw()
	sp:DrawV(320, 240)
end

function testScene_OnClose()
end