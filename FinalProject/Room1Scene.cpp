#include "Room1Scene.hpp"
#include "Room1Scene.hpp"
#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "Player.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"
#include "Box.hpp"

void Room1Scene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    role = new Player(gender,50,200,40,40);
    box = new Box(0,halfW-64,410,128,128);
    background = al_load_bitmap("resources/images/play/playscene.png");

    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("start.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
    //
    
    
}
void Room1Scene::Update(float deltaTime){
    //box->Update(deltaTime);
    role->Update(deltaTime);
}
void Room1Scene::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void Room1Scene::Draw() const{
    
    al_draw_bitmap(background, 0, 0, 0);
    box->Draw();
    role->Draw();
    Group::Draw();
    
}
bool Room1Scene::BoxAndPlayerIsNear(){
    
    if(box->directions==0 || box->directions==1){
        if(role->directions==1&&box->directions==0){
            if(role->Position.y > box->Position.y-100&&role->Position.x < box->Position.x+30 && role->Position.x > box->Position.x - 30)
                return true;
        }
        else if(role->directions==0&&box->directions==1){
            if(role->Position.y < box->Position.y+100&&role->Position.x < box->Position.x+30 && role->Position.x > box->Position.x - 30)
                return true;
        }
    }
    else if(box->directions==2 || box->directions==3){
        if(role->directions==2&&box->directions==3){
            if(role->Position.x < box->Position.x+100&&role->Position.y < box->Position.y+30 && role->Position.y > box->Position.y - 30)
                return true;
        }
        else if(role->directions==3&&box->directions==2){
            if(role->Position.x > box->Position.x-100&&role->Position.y < box->Position.y+30 && role->Position.y > box->Position.y - 30)
                return true;
        }
    }
    
    
    return false;
}
void Room1Scene::OnKeyDown(int keyCode){
    
    
    if(keyCode==ALLEGRO_KEY_UP){
        role->keyState[0] = true;
        if(role->directions!=0){
            //keyState[role->directions] = false;
            role->directions = 0;
        }
        
    }
    if(keyCode==ALLEGRO_KEY_DOWN){
        role->keyState[1] = true;
        if(role->directions!=1){
            //keyState[role->directions] = false;
            role->directions = 1;
        }
        
    }
    if(keyCode==ALLEGRO_KEY_LEFT){
        role->keyState[2] = true;
        if(role->directions!=2){
            //keyState[role->directions] = false;
            role->directions = 2;
        }
    }
    if(keyCode==ALLEGRO_KEY_RIGHT){
        role->keyState[3] = true;
        if(role->directions!=3){
            //keyState[role->directions] = false;
            role->directions = 3;
        }
    }
    if(keyCode==ALLEGRO_KEY_SPACE && BoxAndPlayerIsNear()){
        box->state = 1;
    }
    
}
void Room1Scene::OnKeyUp(int keyCode){
    
    if(keyCode==ALLEGRO_KEY_UP){
        role->keyState[0] = false;
    }
    if(keyCode==ALLEGRO_KEY_DOWN){
        role->keyState[1] = false;
    }
    if(keyCode==ALLEGRO_KEY_LEFT){
        role->keyState[2] = false;
    }
    if(keyCode==ALLEGRO_KEY_RIGHT){
        role->keyState[3] = false;
    }
}
