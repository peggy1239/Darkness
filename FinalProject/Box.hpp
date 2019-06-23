#ifndef Box_hpp
#define Box_hpp
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "Point.hpp"
#include <random>

class PlayScene;

class Box{
protected:
    PlayScene* getPlayScene();
    
public:
    Engine::Point Position;
    Engine::Point Size;
    int directions;//面向 0 1 2 3
    int state = 0;//false for close
    std::vector<ALLEGRO_BITMAP*> picture = {NULL};
    Box(int directions,float x,float y,float w,float h);
    //void Update(float deltaTime) ;
    void Draw()const ;
    ~Box();
};

#endif /* Box_hpp */
