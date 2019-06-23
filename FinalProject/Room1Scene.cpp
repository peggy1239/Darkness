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
#include "LoseScene.hpp"
#include "Trap.hpp"


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
    trap = new Trap(halfW+100,100,96,96);
    subtitle -> visible = true;
    key = 0;
    lives = 5;
    subtitling = true;
    
    background = al_load_bitmap("resources/images/play/playscene.png");
    AddNewObject(new Engine::Label("Room 1", "lunchds.ttf", 36, 100, 50 , 255, 255, 255, 255, 0.5, 0.5));
    if(IsMute==1){
        bgmInstance = al_create_sample_instance(Engine::Resources::GetInstance().GetSample("room.ogg").get());
        al_set_sample_instance_playmode(bgmInstance, ALLEGRO_PLAYMODE_LOOP);
        al_attach_sample_instance_to_mixer(bgmInstance, al_get_default_mixer());
        al_play_sample_instance(bgmInstance);
    }
    //
    
    
}
bool Room1Scene::TrapTrap(){
    
    int Rx = role->Position.x ;
    int Ry = role->Position.y;
    int x1 = trap->Position.x - role->Size.x - 40;
    int x2 = trap->Position.x + trap->Size.x-30;
    int y1 = trap->Position.y - role->Size.y;
    int y2 = trap->Position.y + trap->Size.y-50;
    
    if(Rx>x1&&Rx<x2&Ry>y1&&Ry<y2)
        return true;
    else
        return false;
    
    return false;
}
void Room1Scene::Update(float deltaTime){
    //box->Update(deltaTime);
    role->Update(deltaTime);
    if(door->opendoor){
        Room2Scene* scene = dynamic_cast<Room2Scene*>(Engine::GameEngine::GetInstance().GetScene("room2"));
        scene->gender = gender;
        scene->lives = lives;
        scene->IsMute = IsMute;
        Engine::GameEngine::GetInstance().ChangeScene("room2");
    }
    if(TrapTrap()){
        LoseScene* scene = dynamic_cast<LoseScene*>(Engine::GameEngine::GetInstance().GetScene("lose"));
        scene->IsMute = IsMute;
        role->Position.x = 50;
        role->Position.y = 325;
        lives--;
        if(lives==0){
            Engine::GameEngine::GetInstance().ChangeScene("lose");
        }
    }
    
    
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
    trap->Draw();
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
    
    if(keyCode==ALLEGRO_KEY_SPACE)
        std::cout << "subtitle " << subtitle -> state << std::endl;
    
    if(keyCode==ALLEGRO_KEY_SPACE && BoxAndPlayerIsNear()){
        box->state = 1;
        key = 1;
        KEY->visible = true;
    }
    
    if (keyCode==ALLEGRO_KEY_SPACE)
    {
        if (subtitling == true && !InfrontDoor())
        {
            subtitle -> state ++;
            if (subtitle -> state == 2)
            {
                subtitling = false;
                subtitle -> visible = false;
                subtitle -> state = 3;
            }
        }
    }
    
    if (keyCode==ALLEGRO_KEY_SPACE && subtitle -> state == 2)
    {
        subtitling = false;
        subtitle -> visible = false;
        subtitle -> state = 3;
    }
    
    
    else if(keyCode==ALLEGRO_KEY_SPACE && InfrontDoor())
    {
        if (key==1)
        {
            door->state = 9;
            role->opendoor = true;
            std::cout << "DOOR: " << door -> state << std::endl;
        }
        if (key==0)
        {
            subtitling = true;
            subtitle -> visible =  true;
            subtitle -> state = 2;
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
