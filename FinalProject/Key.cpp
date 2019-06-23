//
//  Key.cpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/23.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#include "Key.hpp"
#include <iostream>
Key::Key(float x,float y,float w,float h){
    Img = al_load_bitmap("resources/images/play/key.png");
    if (Img)
        std::cout << "Load Key" << std::endl;
    Position.x = x;
    Position.y = y;
    Size.x = w;
    Size.y = h;
    visible = false;
}

//void Update(float deltaTime) ;
void Key::Draw()const {
    
    if(visible)al_draw_bitmap(Img, Position.x, Position.y, 0);
}

Key::~Key(){
    al_destroy_bitmap(Img);
}
