

//
//  Room1Scene.cpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/2.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#include "Room1Scene.hpp"
#include "Room1Scene.hpp"
#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"

void Room1Scene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    
    //Engine::Image img("Start.png",0,0,800,600,400,300);
    //AddNewObject(new Engine::Image("Start.png",0,0,800,600,400,300));
    
    
    AddNewObject(new Engine::Label("Darkness", "Gore.ttf", 120, halfW, halfH-50, 255, 0, 0, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("Press enter to start", "Gore.ttf", 30, halfW, halfH+50 , 255, 255, 255, 255, 0.5, 0.5));
    
    
    // Not a safe way, however we only free while change scene, so it's fine.
    ///*
    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("start.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
    //
    
    
}
void Room1Scene::BackOnClick(int stage) {
    // Change to select scene.
    //Engine::GameEngine::GetInstance().ChangeScene("stage-select");
    
    //PlayScene* scene = dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("stage-select"));
    //scene->MapId = stage;
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void Room1Scene::Draw() const{
    ALLEGRO_BITMAP* StartImg = al_load_bitmap("resources/images/start/Start.png");
    al_draw_bitmap(StartImg, 0, 0, 1);
    Group::Draw();
    
}

void Room1Scene::OnKeyDown(int keyCode){
    
    if(keyCode==ALLEGRO_KEY_ENTER){
        
        Engine::GameEngine::GetInstance().ChangeScene("player-select");
    }
    
    
}
