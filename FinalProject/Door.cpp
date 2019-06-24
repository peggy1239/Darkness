#include "Door.hpp"
#include <iostream>

Door::Door(){
    
    picture[0]=al_load_bitmap("resources/images/play/door0.png");
    
    //picture[1]=al_load_bitmap("resources/images/play/door1.png");
    //picture[2]=al_load_bitmap("resources/images/play/door2.png");
    //picture[3]=al_load_bitmap("resources/images/play/door3.png");
    //picture[4]=al_load_bitmap("resources/images/play/door4.png");
    //picture[5]=al_load_bitmap("resources/images/play/door5.png");
    //picture[6]=al_load_bitmap("resources/images/play/door6.png");
    //picture[7]=al_load_bitmap("resources/images/play/door7.png");
    //picture[8]=al_load_bitmap("resources/images/play/door8.png");
    picture[1]=al_load_bitmap("resources/images/play/door9.png");
    /*
    for (int i=1; i<10; i+=2) {
        if(!picture[i])
            std::cout << "error in "<<i<<std::endl;
    }
     */

    Position.x = 30;
    Position.y = -25;
    Size.x = 800;
    Size.y = 600;
    state = 0;//close
    opendoor = false;
}


void Door::Draw(){

    if(state==0)
        al_draw_bitmap(picture[0], Position.x, Position.y, 0);
    else if(state==9)
    {
        al_draw_bitmap(picture[1], Position.x, Position.y, 0);
        opendoor = true;
    }
    
}

Door::~Door(){
    
    al_destroy_bitmap(picture[0]);
    al_destroy_bitmap(picture[1]);
    
}
