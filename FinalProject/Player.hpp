#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "GameEngine.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"
class PlayScene;
class Player{
    
public:
    PlayScene* getPlayScene();
    std::vector<ALLEGRO_BITMAP*> picture = {NULL};
    int direction;//{0,1,2,3} = {up,down,left,right}
    Engine::Point Velocity;
    Engine::Point Position;
    Engine::Point Size;
    bool gender;
    
    Player(float x,float y,float w,float h,int directions,bool gender);
    void Draw() const;
    
    
    
};




#endif // ENEMY_HPP
