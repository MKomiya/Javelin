#include "TestScene.h"
#include "DxFont.h"
#include "Texture.h"
#include "Sprite.h"
#include "BGMusic.h"
#include "Input.h"

TestScene::TestScene(void) : font(NULL), tex(NULL), sprite(NULL)
{
}

TestScene::~TestScene(void)
{
	this->RemoveObject(font);
	delete tex;
	delete sprite;
}

void TestScene::Init()
{
	font = new DxFont();
	this->AppendObject(font, 1, true);
	this->AppendItemBox("font", font);

	tex = new Texture("soccerball.png");
	sprite = new Sprite(tex);
	this->AppendItemBox("tex", tex);
	this->AppendItemBox("sprite", sprite);

	r=0.f;

	AppendObject(new BGMusic("Kalimba.mp3"), 5, "BGM", true);
	AppendItemBox("BGM", FindObject("BGM"));
	bgm = dynamic_cast<BGMusic*>(this->FindItemBox("BGM"));
	//if(bgm) bgm->Play();

    input = (Input*)FindObject("input");  
    if(input == NULL){  
        input = new Input();  
        AppendObject(input, 0, "input", true);  
    } 

	sound.Load("missile.wav");
	Sound *se = new Sound(*(Sound*)FindItemBox("burst"));
	//se->EnableDeleteByEnd();
	se->Play();
}

void TestScene::Exec()
{
	font->Draw("•¶Žš—ñ•`‰æ", 320, 240);
	sprite->DrawV(320, 240, 2.0f, 2.f, r++, 128);
	if( input->IsKeyDown(DIK_Z) )
	{
		sound.Play();
	}
}