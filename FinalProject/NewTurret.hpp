//
//  NewTurret.hpp
//  TowerDefense
//
//  Created by lo peichieh on 2019/5/26.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#ifndef NewTurret_hpp
#define NewTurret_hpp

#include "PlayScene.hpp"
#include "Bullet.hpp"
#include "Turret.hpp"

class PlayScene;
class NewTurret: public Turret {
public:
    static const int Price;
    NewTurret(float x, float y);
    void CreateBullet() override;
};


#endif /* NewTurret_hpp */
