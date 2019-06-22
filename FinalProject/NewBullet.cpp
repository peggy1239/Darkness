//
//  NewBullet.cpp
//  TowerDefense
//
//  Created by lo peichieh on 2019/5/26.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#include "NewBullet.hpp"
#include "DirtyEffect.hpp"

NewBullet::NewBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
Bullet("play/bullet-10.png", 500, 1000, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 2 (1/8): You can imitate the 2 files: 'FireBullet.hpp', 'FireBullet.cpp' to create a new bullet.
}
void NewBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}


