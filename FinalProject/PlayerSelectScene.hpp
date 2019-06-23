#ifndef PlayerSelectScene_HPP
#define PlayerSelectScene_HPP
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"

class PlayerSelectScene final : public Engine::IScene {
private:
	ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
	explicit PlayerSelectScene() = default;
	void Initialize() override;
	void StartOnClick(int stage);
	void BGMSlideOnValueChanged(float value);
	void SFXSlideOnValueChanged(float value);
    int IsMute;//0 for mute
};

#endif // PlayerSelectScene_HPP
