//
//  Key.hpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/23.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#ifndef Key_hpp
#define Key_hpp

#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "Point.hpp"
#include <random>

class PlayScene;

class Key{
protected:
    PlayScene* getPlayScene();
    
public:
    Engine::Point Position;
    Engine::Point Size;
    bool visible = false;
    ALLEGRO_BITMAP* Img = NULL;
    Key(float x,float y,float w,float h);
    //void Update(float deltaTime) ;
    void Draw()const ;
    ~Key();
};

#endif /* Key_hpp */
