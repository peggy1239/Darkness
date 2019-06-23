#include "Subtitle2.hpp"
#include <iostream>

Subtitle2::Subtitle2(float x,float y,float w,float h){

    subpicture[0] = al_load_bitmap("resources/images/play/room2sub1.png");

    Position.x = x;
    Position.y = y;
    Size.x = w;
    Size.y = h;
    visible = false;

}

void Subtitle2::Draw()const{
    if (visible)
        al_draw_bitmap(subpicture[0], Position.x, Position.y, 0);
}

Subtitle2::~Subtitle2(){

    al_destroy_bitmap(subpicture[0]);
    /*
    for(int i=0;i<2;i++){
        if(picture[i]!=NULL){
            al_destroy_bitmap(picture[i]);
        }
    }
     */

}


