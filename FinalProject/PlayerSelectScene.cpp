#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "AudioHelper.hpp"
#include "Slider.hpp"
#include "LOG.hpp"

void PlayerSelectScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
   
    Engine::ImageButton* btn;
    
    btn = new Engine::ImageButton("player-select/boy1.png", "player-select/boy2.png", halfW-330, 125,280 , 360);
    btn->SetOnClickCallback(std::bind(&PlayerSelectScene::StartOnClick,this,1));
    AddNewControlObject(btn);
    
    btn = new Engine::ImageButton("player-select/girl1.png", "player-select/girl2.png", halfW+50, 125, 280, 360);
    
    btn->SetOnClickCallback(std::bind(&PlayerSelectScene::StartOnClick,this,2));
    AddNewControlObject(btn);
    
    AddNewObject(new Engine::Label("YOU ARE...", "OldGateLaneNF.ttf", 52, halfW, halfH-250, 255, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("MALE", "OldGateLaneNF.ttf", 38, halfW-200, halfH+230 , 255, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("FEMALE", "OldGateLaneNF.ttf", 38, halfW+200, halfH+230 , 255, 255, 255, 255, 0.5, 0.5));

   
    
    
}
void PlayerSelectScene:: StartOnClick(int stage){
    //True for male; False for female
    PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("room1"));
    if (stage == 1)
        scene -> gender = true;
    else
        scene -> gender = false;
    
    Engine::GameEngine::GetInstance().ChangeScene("room1");
}

/*
void PlayerSelectScene::BGMSlideOnValueChanged(float value) {
    al_set_sample_instance_gain(bgmInstance, value);
    AudioHelper::BGMVolume = value;
}
void PlayerSelectScene::SFXSlideOnValueChanged(float value) {
    AudioHelper::SFXVolume = value;
}
*/
