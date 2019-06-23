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
    
    for(int i=0;i<3;i++){
        if(blockarea[i][0]!=0){
            if(Position.x > blockarea[i][0] && Position.x < blockarea[i][1]){
                if(Position.y > blockarea[i][2]-Size.y && Position.y < blockarea[i][2]){
                    Position.y = blockarea[i][2]-Size.y;
                }
                if(Position.y < blockarea[i][3]+Size.y && Position.y > blockarea[i][3]){
                    Position.y = blockarea[i][3]+Size.y;
                }
            }
            if(Position.y > blockarea[i][2] && Position.y < blockarea[i][3]){
                if(Position.x > blockarea[i][0]-Size.x && Position.x < blockarea[i][0]){
                    Position.x = blockarea[i][0]-Size.x;
                }
                if(Position.x < blockarea[i][1]+Size.x && Position.x > blockarea[i][1]){
                    Position.x = blockarea[i][1]+Size.x;
                }
            }
        }
        
    }
    
    
    
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
void Player:: Block(int num,int x1,int x2,int y1,int y2){
    
    blockarea[num][0] = x1;
    blockarea[num][1] = x2;
    blockarea[num][2] = y1;
    blockarea[num][3] = y2;
    
}
