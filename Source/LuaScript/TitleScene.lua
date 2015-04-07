class("TitleScene") {
}

function TitleScene:ctor(...)
	self.text = DxFont(24)
	self.x = 0
	self.y = 0
	self.count = 0

	self.buttons = {}
	local texts = {
		"はじめから",
		"つづきから",
		"設定を変更する",
		"ゲームを終了する",
	}

	for i=1, 5 do
		self.buttons[i] = Button:new()
		self.buttons[i]:init(700, 100+i*32, texts[i])
	end

	self.line = Figure()
end

function TitleScene:Update()
	for i=1, 5 do
		self.buttons[i]:move()
	end

	self.x = math.cos(self.count/30)
	self.y = math.sin(self.count/30)

	self.count = self.count + 1
end

function TitleScene:Draw()
	for i=1, 5 do
		self.buttons[i]:drawtext()
	end
	self.text:Draw("タイトル画面らしいよー", 100+50*self.x, 120+50*self.y)
	--self.text:Draw("Copyright：AceSpring", 30, 400)

	self.line:DrawBox(100, 100, 300, 200, 0xffffffff)
end

class("Button"){
}

function Button:ctor(...)
	self.x = 0
	self.y = 0
	self.text = ""
	self.draw = DxFont(12)
end

function Button:init(x, y, text)
	self.x = x
	self.y = y
	self.text = text
end

function Button:move()
	if self.x <= 300 then
		return
	end
	self.x = self.x - 2
end

function Button:drawtext()
	self.draw:Draw(self.text, self.x, self.y)
end