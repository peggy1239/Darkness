#ifndef Subtitle_hpp
#define Subtitle_hpp
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "Point.hpp"
#include <random>

class PlayScene;

class Subtitle{
protected:
    PlayScene* getPlayScene();
    
public:
    Engine::Point Position;
    Engine::Point Size;
    int gender;
    bool visible;
    int state = 0; //0 for 1 1 for 1 2 for none
    std::vector<ALLEGRO_BITMAP*> subpicture = {NULL};
    Subtitle(int gender, float x,float y,float w,float h);
    //void Update(float deltaTime) ;
    void Draw()const ;
    ~Subtitle();
};

#endif
