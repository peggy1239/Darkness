#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "PlayerSelectScene.hpp"

class StartScene final : public Engine::IScene {
private:
    ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
    int IsMute;
    explicit StartScene() = default;
    void Initialize() override;
    void BackOnClick(int stage);
    void Draw() const override;
    void OnKeyDown(int keyCode) override;
    //void IsMute(float value);
    //void OnMouseDown(int button, int mx, int my) override;
    //void Update(float deltaTime) override;
    
    
};

#endif // PlayerSelectScene_HPP
