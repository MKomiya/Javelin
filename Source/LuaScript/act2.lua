function act2_OnStart()
	tex2 = Texture("g/anime.png")
	sp2 = Sprite(tex2)
	sp2:SetSpriteSize(128, 128)

	count, frame = 0, 0
end

function act2_OnFrame()
	count = count + 1
	if count >= 12 then
		count = 0
		frame = frame + 1
		if frame >= 8 then
			frame = 0
		end
		sp2:SetFrame(frame)
	end
end

function act2_OnDraw()
	sp2:DrawV(320-64, 240-64)
end

function act2_OnVanish()
end