#include "Player.hpp"
#include <iostream>

Player:: Player(int gender,float x,float y,float w,float h){
    
    //load images
    if(gender==0){
        pic[0] = al_load_bitmap("resources/images/play/player_boy0.png");
        pic[1] = al_load_bitmap("resources/images/play/player_boy1.png");
        pic[2] = al_load_bitmap("resources/images/play/player_boy2.png");
        pic[3] = al_load_bitmap("resources/images/play/player_boy3.png");
    }
    else if(gender==1){
        pic[0] = al_load_bitmap("resources/images/play/player_girl0.png");
        pic[1] = al_load_bitmap("resources/images/play/player_girl1.png");
        pic[2] = al_load_bitmap("resources/images/play/player_girl2.png");
        pic[3] = al_load_bitmap("resources/images/play/player_girl3.png");
    }
   
    
    Position.x = x;
    Position.y = y;
    Size.x = w;
    Size.y = h;
    directions = 3;
    this->gender=gender;
    opendoor = false;
    Velocity.x = Velocity.y = 5;//velocity setting
    
    
}
void Player:: Update(float deltaTime){
    if(!opendoor){
        if(keyState[0]){
            Position.y -= Velocity.y;
        }
        if(keyState[1]){
            Position.y += Velocity.y;
        }
        if(keyState[2]){
            Position.x -= Velocity.x;
        }
        if(keyState[3]){
            Position.x += Velocity.x;
        }
    }
    
    
    if (Position.x < 0)
        Position.x = 0;
    if (Position.x > 680)
        Position.x = 680;
    if (Position.y < 100)
        Position.y = 100;
    if (Position.y > 380)
        Position.y = 380;
}


void Player:: Draw()const {
    
    //std::cout << "directions: " << directions << std::endl;
    al_draw_bitmap(pic[directions], Position.x, Position.y, 0);
    
    
    
    
}
Player::~Player(){
    
    for (int i=0; i<4; i++) {
        al_destroy_bitmap(pic[i]);
    }
    
}
