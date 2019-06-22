//
//  HowScene.hpp
//  FinalProject
//
//  Created by lo peichieh on 2019/6/22.
//  Copyright © 2019 lo peichieh. All rights reserved.
//

#ifndef HowScene_hpp
#define HowScene_hpp

#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "PlayerSelectScene.hpp"

class HowScene final : public Engine::IScene {
private:
    ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
    explicit HowScene() = default;
    void Initialize() override;
    void BackOnClick(int stage);
    void Draw() const override;
    void OnKeyDown(int keyCode) override;
};

#endif /* HowScene_hpp */
