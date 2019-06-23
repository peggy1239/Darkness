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
    bool opendoor;
    int blockarea[3][4] = {0};
    bool keyState[4] = {false};
    std::vector<ALLEGRO_BITMAP*> pic = {NULL};//0 for male
    Player(int gender,float x,float y,float w,float h);
    ~Player();
    void Update(float deltaTime) ;
    void Draw()const ;
    void Block(int num,int x1,int x2,int y1,int y2);
};
#endif // BULLET_HPP

