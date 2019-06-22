#include "Room1Scene.hpp"
#include "Room1Scene.hpp"
#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "Player.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"

void Room1Scene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    role = new Player(gender,50,200,40,40);
    
    background = al_load_bitmap("resources/images/play/playscene.png");

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
    
    al_draw_bitmap(background, 0, 0, 1);
    role->Draw();
    Group::Draw();
    
}

void Room1Scene::OnKeyDown(int keyCode){
    
    if(keyCode==ALLEGRO_KEY_ENTER){
        
        Engine::GameEngine::GetInstance().ChangeScene("player-select");
    }
    
    
}
