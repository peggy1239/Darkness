#include "GameEngine.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"
#include "Player.hpp"

PlayScene* Player::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

Player:: Player(float x,float y,float w,float h,int direction,bool gender){
    Position.x = x;
    Position.y = y;
    this->direction = direction;
    Size.x =w;
    Size.y =h;
    this->gender = gender;
    if(gender){
        picture[0]=al_load_bitmap("resources/images/player/player_boy0");
        picture[1]=al_load_bitmap("resources/images/player/player_boy1");
        picture[2]=al_load_bitmap("resources/images/player/player_boy2");
        picture[3]=al_load_bitmap("resources/images/player/player_boy3");
    }
    else{
        picture[0]=al_load_bitmap("resources/images/player/player_girl0");
        picture[1]=al_load_bitmap("resources/images/player/player_girl1");
        picture[2]=al_load_bitmap("resources/images/player/player_girl2");
        picture[3]=al_load_bitmap("resources/images/player/player_girl3");
    }
    
    
}
void Player::Draw()const{
    switch (direction) {
        case 0://up
            al_draw_bitmap(picture[0], Position.x, Position.y, 1);
            break;
        case 1://down
            al_draw_bitmap(picture[1], Position.x, Position.y, 1);
            break;
        case 2://left
            al_draw_bitmap(picture[2], Position.x, Position.y, 1);
            break;
        case 3://right
            al_draw_bitmap(picture[3], Position.x, Position.y, 1);
            break;
            
        default:
            break;
    }
    
    
    
    
    
    
    
}
