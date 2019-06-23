#include "Trap.hpp"
#include <iostream>

Trap::Trap(float x,float y,float w,float h){
    
    picture[0] = al_load_bitmap("resources/images/play/trap.png");

    visible = true;
    Position.x = x;
    Position.y = y;
    Size.x = w;
    Size.y = h;
    
}

void Trap::Draw()const{
    
    if(visible){
       
        al_draw_bitmap(picture[0], Position.x, Position.y, 0);
        
    }
    
}

Trap::~Trap(){
    
    al_destroy_bitmap(picture[0]);
    
}
