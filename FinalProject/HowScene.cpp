//
//  HowScene.cpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/22.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#include "HowScene.hpp"
#include "StartScene.hpp"
#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"

void HowScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    
    Engine::ImageButton* btn;
    
    btn = new Engine::ImageButton("lose/exit1.png", "lose/exit2.png", halfW +30, halfH * 3 / 2 - 100, 280, 120);//EXIT
    btn->SetOnClickCallback(std::bind(&HowScene::BackOnClick, this, 2));
    AddNewControlObject(btn);
    
    
    // Not a safe way, however we only free while change scene, so it's fine.
    ///*
    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("start.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
    //
    
    
}
void HowScene::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("start");
}

void HowScene::Draw() const{
    ALLEGRO_BITMAP* StartImg = al_load_bitmap("resources/images/scene/howscene.png");
    al_draw_bitmap(StartImg, 0, 0, 1);
    Group::Draw();
    
}

void HowScene::OnKeyDown(int keyCode){
    
    if(keyCode==ALLEGRO_KEY_ENTER){
        
        Engine::GameEngine::GetInstance().ChangeScene("player-select");
    }
    
    
}
