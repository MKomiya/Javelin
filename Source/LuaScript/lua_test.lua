-- �Q�[���̏���������
-- �E�B���h�E�𐶐����ADirectX��������������A��x�������s����܂�
function InitGame()

	tex = Texture("anime.png")
	sp = Sprite(tex)
	sp:SetSpriteSize(128, 128)
end

-- �Q�[���̍X�V����
-- ���C�����[�v�ŌĂяo�����
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

-- �Q�[���̕`�揈��
function DrawFrame()
	sp:DrawV(320, 240)
end

-- �Q�[���̏I������
function EndGame()
end