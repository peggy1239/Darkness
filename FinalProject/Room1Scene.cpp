#include "Room1Scene.hpp"
#include "Room2Scene.hpp"
#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "Player.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"
#include "Box.hpp"
#include "Door.hpp"
#include "Subtitle.hpp"
#include <iostream>
#include "Key.hpp"



void Room1Scene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    role = new Player(gender,50,halfH-75,40,40);
    box = new Box(0,halfW-65,410,128,128);
    subtitle = new Subtitle(gender, 0, 0, 800, 600);
    door = new Door();
    KEY = new Key(false,w-100,h-80,50,50);
    for (int i=0; i<5; i++) {
        heart[i] = new Box(6,w-60-i*55,10,50,50);
    }
    key = false;
    sub=0;
    lives = 5;
    subtitling = true;
    
    background = al_load_bitmap("resources/images/play/playscene.png");
    AddNewObject(new Engine::Label("Room 1", "lunchds.ttf", 36, 100, 50 , 255, 255, 255, 255, 0.5, 0.5));
    
    bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("room.ogg").get());
    al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
    al_play_sample_instance(bgmInstance);
    
    //
    
    
}
void Room1Scene::Update(float deltaTime){
    //box->Update(deltaTime);
    role->Update(deltaTime);
    Room2Scene* scene = dynamic_cast<Room2Scene*>(Engine::GameEngine::GetInstance().GetScene("room2"));
    scene->gender = gender;
    scene->lives = lives;
    if(door->opendoor)
        Engine::GameEngine::GetInstance().ChangeScene("room2");
    
    
}
void Room1Scene::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void Room1Scene::Draw() const{
    
    al_draw_bitmap(background, 0, 0, 0);
    box->Draw();
    role->Draw();
    door->Draw();
    KEY->Draw();
    subtitle -> Draw();
    for (int i=0; i<lives; i++) {
        heart[i]->Draw();
    }
    Group::Draw();
    
    
}

bool Room1Scene::InfrontDoor()
{
    if (role->Position.x == 680 && (role->Position.y <=260 && role->Position.y >=210) && role->directions == 3)
        return true;
    else
        return false;
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
    
    if (!subtitling){
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
    }
    
    if(keyCode==ALLEGRO_KEY_SPACE && BoxAndPlayerIsNear()){
        box->state = 1;
        key = true;
        KEY->visible = true;
    }
    
    if(keyCode==ALLEGRO_KEY_SPACE && subtitling == true)
    {
        std::cout << "subtitle" << std::endl;
        subtitle -> state ++;
        if (subtitle -> state == 2)
        {
            subtitling = false;
        }
    }
    
    if(keyCode==ALLEGRO_KEY_SPACE && key )
    {
        if (InfrontDoor())
        {
            //door->opendoor();
            door->state = 9;
            role->opendoor = true;
            std::cout << "DOOR: " << door -> state << std::endl;
        }
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
void Room1Scene::Terminate(){
    
    std::cout<< "TERMINATE IN ROOM!\n";
    delete role;
    std::cout<< "delete role\n";
    delete box;
    std::cout<< "delete box\n";
    //delete guider;
    std::cout<< "delete guider\n";
    delete door;
    std::cout<< "delete door\n";
    al_destroy_bitmap(background);
    Clear();
    std::cout<< "TERMINATE SUCCEED!\n";
}
