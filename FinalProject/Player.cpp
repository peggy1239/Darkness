//
//  Player.cpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/21.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

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
    else{
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
    Velocity.x = Velocity.y = 5;//velocity setting
    
    
}
void Player:: Update(float deltaTime){
    
    
    
}
void Player:: Draw()const {
    
    std::cout << "directions: " << directions << std::endl;
    al_draw_bitmap(pic[directions], Position.x, Position.y, 1);
    
    
    
    
}
