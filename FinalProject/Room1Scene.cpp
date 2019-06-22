

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
    
    Player* role = new Player(100,400,50,50,3,gender);
    
    
    
    
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
     
    role->Draw();
    
}


