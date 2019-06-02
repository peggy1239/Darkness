//
//  Room1Scene.hpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/2.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#ifndef Room1Scene_hpp
#define Room1Scene_hpp
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "PlayerSelectScene.hpp"

class Room1Scene final : public Engine::IScene {
private:
    ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
    explicit Room1Scene() = default;
    void Initialize() override;
    void BackOnClick(int stage);
    void Draw() const override;
    void OnKeyDown(int keyCode) override;
};
#endif /* Room1Scene_hpp */
