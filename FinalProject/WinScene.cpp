#include "WinScene.hpp"
#include "Room1Scene.hpp"
#include "Label.hpp"
#include "AudioHelper.hpp"
#include "PlayScene.hpp"

void WinScene::Initialize() {
	ticks = 0;
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
	int halfW = w / 2;
	int halfH = h / 2;
	//AddNewObject(new Engine::Label("YOU ESCAPED!", "Gore.ttf", 48, halfW, halfH / 2, 255, 255, 255, 255, 0.5, 0.5));
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("lose/again1.png", "lose/again2.png", halfW - 300, halfH * 3 / 2 -100, 280, 120);//AGAIN
    btn->SetOnClickCallback(std::bind(&WinScene::BackOnClick, this, 1));
    AddNewControlObject(btn);
    
    btn = new Engine::ImageButton("lose/exit1.png", "lose/exit2.png", halfW +30, halfH * 3 / 2 - 100, 280, 120);//EXIT
    btn->SetOnClickCallback(std::bind(&WinScene::BackOnClick, this, 2));
    AddNewControlObject(btn);
    if(IsMute==1)
	 AudioHelper::PlayAudio("win.ogg");
}
void WinScene::Update(float deltaTime) {
	
}
void WinScene::BackOnClick(int stage) {
	// Change to select scene.
    Room1Scene* scene = dynamic_cast<Room1Scene*>(Engine::GameEngine::GetInstance().GetScene("room1"));
    if(stage==1){
        scene->key = false;
        Engine::GameEngine::GetInstance().ChangeScene("room1");
    }
    else
        Engine::GameEngine::GetInstance().ChangeScene("start");
}
void WinScene::Draw() const{
    ALLEGRO_BITMAP* StartImg = al_load_bitmap("resources/images/win/winscene.png");
    al_draw_bitmap(StartImg, 0, 0, 0);
    Group::Draw();
    
}
