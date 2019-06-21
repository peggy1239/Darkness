#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Sprite.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "Turret.hpp"
#include <random>

class PlayScene;

class Player : public Engine::Sprite {
protected:
    //float
    int lives;
    PlayScene* getPlayScene();
public:
    explicit Player(std::string img, float speed, Engine::Point position, Engine::Point forwardDirection, float rotation);
    void Update(float deltaTime) override;
};
#endif // BULLET_HPP
