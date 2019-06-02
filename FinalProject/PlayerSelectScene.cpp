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
    
    btn = new Engine::ImageButton("player-select/dirt.png", "player-select/floor.png", halfW-100, halfH * 3 / 2 - 50, 150, 50);
    btn->SetOnClickCallback(std::bind(&PlayerSelectScene::StartOnClick,this,2));
    AddNewControlObject(btn);
    
    btn = new Engine::ImageButton("player-select/dirt.png", "player-select/floor.png", halfW+100, halfH * 3 / 2 - 50, 150, 50);
    
    btn->SetOnClickCallback(std::bind(&PlayerSelectScene::StartOnClick,this,2));
    AddNewControlObject(btn);
    
    AddNewObject(new Engine::Label("YOU ARE...", "Black.ttf", 48, halfW, halfH-250, 255, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("MALE", "Black.ttf", 24, halfW-200, halfH+250 , 255, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("FEMALE", "Black.ttf", 24, halfW+200, halfH+250 , 255, 255, 255, 255, 0.5, 0.5));

   
    
    
}
void PlayerSelectScene:: StartOnClick(int stage){
    
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
