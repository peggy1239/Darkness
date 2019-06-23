#ifndef Subtitle2_hpp
#define Subtitle2_hpp
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "Point.hpp"
#include <random>

class PlayScene;

class Subtitle2{
protected:
    PlayScene* getPlayScene();
    
public:
    Engine::Point Position;
    Engine::Point Size;
    int state = 0; //
    bool visible;
    std::vector<ALLEGRO_BITMAP*> subpicture = {NULL};
    Subtitle2(float x,float y,float w,float h);
    //void Update(float deltaTime) ;
    void Draw()const ;
    ~Subtitle2();
};

#endif
