function testActor_OnStart()
	tex = Texture("g/soccerball.png")
	sp = Sprite(tex)
	x, y = 320, 240
	dx, dy = 2, -2
end

function testActor_OnFrame()
	x = x + dx
	y = y + dy

	if x >= 640 - 16 or x <= 0 then
		dx = dx * -1
	end
	if y >= 480 - 16 or y <= 0 then
		dy = dy * -1
	end
end

function testActor_OnDraw()
	sp:DrawV(x, y)
end

function testActor_OnVanish()
end