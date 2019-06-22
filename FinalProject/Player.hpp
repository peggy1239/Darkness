#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include "Point.hpp"
#include <random>

class PlayScene;

class Player{
protected:
    //float
    int lives;
    PlayScene* getPlayScene();
public:
    Engine::Point Position;
    Engine::Point Size;
    Engine::Point Velocity;
    int directions;
    int gender;
    std::vector<ALLEGRO_BITMAP*> pic = {NULL};//0 for male
    Player(int gender,float x,float y,float w,float h);
    void Update(float deltaTime) ;
    void Draw()const ;
};
#endif // BULLET_HPP

