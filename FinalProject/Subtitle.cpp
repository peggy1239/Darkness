#include "Subtitle.hpp"
#include <iostream>

Subtitle::Subtitle(int gender,float x,float y,float w,float h){

    if (gender == 0)
    {
        subpicture[0] = al_load_bitmap("resources/images/play/boyroom1sub1.png");
        subpicture[1] = al_load_bitmap("resources/images/play/boyroom1sub2.png");
    }
    if (gender == 1)
    {
        subpicture[0] = al_load_bitmap("resources/images/play/girlroom1sub1.png");
        subpicture[1] = al_load_bitmap("resources/images/play/girlroom1sub2.png");
    }

    Position.x = x;
    Position.y = y;
    Size.x = w;
    Size.y = h;
    this -> gender = gender;

}

void Subtitle::Draw()const{
    if (state == 1 || state == 0)
        al_draw_bitmap(subpicture[state], Position.x, Position.y, 0);
}

Subtitle::~Subtitle(){

    al_destroy_bitmap(subpicture[0]);
    /*
    for(int i=0;i<2;i++){
        if(picture[i]!=NULL){
            al_destroy_bitmap(picture[i]);
        }
    }
     */

}

