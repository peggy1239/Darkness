#include "Box.hpp"
#include <iostream>

Box::Box(int directions,float x,float y,float w,float h){
    
    
        
        if(directions==0){
            //std::cout<<"I'm IN!\n";
            
            picture[0] = al_load_bitmap("resources/images/play/box00.png");
            picture[1] = al_load_bitmap("resources/images/play/box01.png");
        }
        else if(directions==1){
            picture[0] = al_load_bitmap("resources/images/play/box10.png");
            picture[1] = al_load_bitmap("resources/images/play/box11.png");
        }
        else if(directions==2){
            picture[0] = al_load_bitmap("resources/images/play/box20.png");
            picture[1] = al_load_bitmap("resources/images/play/box21.png");
        }
        else if(directions==3){
            
            picture[0] = al_load_bitmap("resources/images/play/box30.png");
            picture[1] = al_load_bitmap("resources/images/play/box31.png");
        }
        else if(directions==4){
            
            picture[0] = al_load_bitmap("resources/images/play/boy.png");
            
        }
        else if(directions==5){
            
            picture[0] = al_load_bitmap("resources/images/play/girls.png");
        }
        else if(directions==6){//lives
            
            picture[0] = al_load_bitmap("resources/images/play/lives.png");
        }
        else if(directions==7){ //oldman
            picture[0] = al_load_bitmap("resources/images/play/oldman.png");
        }
        
    
    
    this->directions = directions;
    visible = true;
    Position.x = x;
    Position.y = y;
    Size.x = w;
    Size.y = h;
    state = 0;
    
}

void Box::Draw()const{
    
    if(visible){
        al_draw_bitmap(picture[state], Position.x, Position.y, 0);
        if(directions==6){
           
            al_draw_bitmap(picture[0], Position.x, Position.y, 0);
            
        }
    }
    
}

Box::~Box(){
    
    al_destroy_bitmap(picture[0]);
    /*
    for(int i=0;i<2;i++){
        if(picture[i]!=NULL){
            al_destroy_bitmap(picture[i]);
        }
    }
     */
    
}
