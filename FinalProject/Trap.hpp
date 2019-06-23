//
//  Trap.hpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/23.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#ifndef Trap_hpp
#define Trap_hpp
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "Point.hpp"
#include <random>

class PlayScene;

class Trap{
protected:
    PlayScene* getPlayScene();
    
public:
    Engine::Point Position;
    Engine::Point Size;
    int directions;//面向 0 1 2 3
    int lives;
    bool visible;
    std::vector<ALLEGRO_BITMAP*> picture = {NULL};
    Trap(float x,float y,float w,float h);
    //void Update(float deltaTime) ;
    void Draw()const ;
    ~Trap();
};

#endif /* Trap_hpp */
