#include "HowScene.hpp"
#include "HowScene.hpp"
#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"

void HowScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    
    
    AddNewObject(new Engine::Label("Press enter to start...", "Gore.ttf", 28, 590, 580 , 255, 255, 255, 255, 0.5, 0.5));
    
    // Not a safe way, however we only free while change scene, so it's fine.
    ///*
    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("start.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
    //
    
    
}
void HowScene::BackOnClick(int stage) {
    
}

void HowScene::Draw() const{
    ALLEGRO_BITMAP* StartImg = al_load_bitmap("resources/images/how/howscene.png");
    al_draw_bitmap(StartImg, 0, 0, 0);
    Group::Draw();
    
}

void HowScene::OnKeyDown(int keyCode){
    
    if(keyCode==ALLEGRO_KEY_ENTER){
        
        Engine::GameEngine::GetInstance().ChangeScene("player-select");
    }
    
}
