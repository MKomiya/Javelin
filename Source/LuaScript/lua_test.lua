-- ゲームの初期化処理
-- ウィンドウを生成し、DirectXを初期化した後、一度だけ実行されます
function InitGame()

	tex = Texture("anime.png")
	sp = Sprite(tex)
	sp:SetSpriteSize(128, 128)
end

-- ゲームの更新処理
-- メインループで呼び出される
function ProcessFrame()
	
	frame = 0; count = 0
	count = count + 1
	if count >= 12 then
		count = 0
		frame = frame + 1
		if frame >= 8 then frame = 0 end
		sp:SetFrame(frame)
	end
end

-- ゲームの描画処理
function DrawFrame()
	sp:DrawV(320, 240)
end

-- ゲームの終了処理
function EndGame()
end