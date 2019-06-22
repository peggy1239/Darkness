//
//  NewTurret.cpp
//  TowerDefense
//
//  Created by lo peichieh on 2019/5/26.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#include "NewTurret.hpp"
#include "PlayScene.hpp"
#include "MachineGunTurret.hpp"
#include "NewBullet.hpp"
#include "AudioHelper.hpp"

const int NewTurret::Price = 30;
NewTurret::NewTurret(float x, float y) :
// TODO 2 (2/8): You can imitate the 2 files: 'NewTurret.hpp', 'NewTurret.cpp' to create a new turret.
Turret("play/tower-base.png", "play/turret-7.png", x, y, 200, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}
void NewTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new NewBullet(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
