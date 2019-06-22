#include "Room1Scene.hpp"
#include "Room1Scene.hpp"
#include "PlayerSelectScene.hpp"
#include "Room1Scene.hpp"
#include "AudioHelper.hpp"
#include "LOG.hpp"
#define vel 5
//bool Room1Scene::gender = false;
void Room1Scene::Initialize() {
    
    Player* role = new Player(100,400,50,50,3,1);
}
void Room1Scene::BackOnClick(int stage) {

    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}

void Room1Scene::Draw() const{
    
     role->Draw();
    
}
/*
void Room1Scene::Update(float deltaTime) {
    if (deltaTime < 3) {
        IScene::Update(deltaTime);
    } else if (deltaTime < 6) {
        IScene::Update(deltaTime / 2);
        IScene::Update(deltaTime / 2);
    } else if (deltaTime < 9) {
        IScene::Update(deltaTime / 3);
        IScene::Update(deltaTime / 3);
        IScene::Update(deltaTime / 3);
    } else {
        IScene::Update(deltaTime / 4);
        IScene::Update(deltaTime / 4);
        IScene::Update(deltaTime / 4);
        IScene::Update(deltaTime / 4);
    }
    
}
 */
/*
void Room1Scene::OnKeyDown(int keyCode) {
    IScene::OnKeyDown(keyCode);
    
    if (keyCode == ALLEGRO_KEY_UP) {//0
        if(role->direction!=0) role->direction = 0;
        else role->Velocity.y -= vel;//vel for velocity
    }
    if (keyCode == ALLEGRO_KEY_DOWN) {//1

        if(role->direction!=1) role->direction = 1;
        else role->Velocity.y += vel;//vel for velocity
    }
    if (keyCode == ALLEGRO_KEY_LEFT) {//2
        if(role->direction!=2) role->direction = 2;
        else role->Velocity.x -= vel;
    }
    if (keyCode == ALLEGRO_KEY_RIGHT) {//3
        if(role->direction!=3) role->direction = 3;
        else role->Velocity.x += vel;
    }
    // TODO 2 (5/8): Make the R key to create the 4th turret.
    if (keyCode >= ALLEGRO_KEY_0 && keyCode <= ALLEGRO_KEY_9) {
        // Hotkey for Speed up.
        //SpeedMult = keyCode - ALLEGRO_KEY_0;
    }
}
*/

