#ifndef Room1Scene_hpp
#define Room1Scene_hpp
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "PlayerSelectScene.hpp"
#include "Player.hpp"

class Room1Scene final : public Engine::IScene {
private:
    ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
    //void Update(float deltaTime) override;
    static bool gender;
    Player* role;
    explicit Room1Scene() = default;
    void Initialize() override;
    void BackOnClick(int stage);
    void Draw() const override;
    
};
#endif /* Room1Scene_hpp */
