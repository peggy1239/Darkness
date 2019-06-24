//
//  Door.hpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/23.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#ifndef Door_hpp
#define Door_hpp
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "Point.hpp"
#include <random>

class PlayScene;

class Door{
protected:
    PlayScene* getPlayScene();
    
public:
    Engine::Point Position;
    Engine::Point Size;
    int state = 0;//false for close
    bool opendoor;
    std::vector<ALLEGRO_BITMAP*> picture = {NULL};
    Door();
    //void Update(float deltaTime) ;
    void Draw();
    ~Door();
};

#endif /* Door_hpp */
