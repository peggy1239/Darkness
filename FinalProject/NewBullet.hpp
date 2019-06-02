//
//  NewBullet.hpp
//  TowerDefense
//
//  Created by lo peichieh on 2019/5/26.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#ifndef NewBullet_hpp
#define NewBullet_hpp


#include "Bullet.hpp"
class NewBullet : public Bullet {
public:
    explicit NewBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};



#endif /* NewBullet_hpp */
