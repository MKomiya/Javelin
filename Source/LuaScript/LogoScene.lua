class("LogoScene") {
}

function LogoScene:ctor(...)
	self.tex = Texture("g/x68apo.png")
	self.sprite = Sprite(self.tex)
	self.count = 0
end

function LogoScene:Update()
	self.count = self.count + 1
end

function LogoScene:Draw()
	self.sprite:DrawV(320, 240)
end