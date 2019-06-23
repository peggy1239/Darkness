// [main.cpp]
// this template is provided for the 2D tower defense game.
// Program entry point.
// Returns program exit code.
#include "GameEngine.hpp"
#include "LOG.hpp"
#include "PlayerSelectScene.hpp"
#include "PlayScene.hpp"
#include "WinScene.hpp"
#include "LoseScene.hpp"
#include "StartScene.hpp"
#include "Room1Scene.hpp"
#include "Room2Scene.hpp"
#include "HowScene.hpp"


int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene("player-select", new PlayerSelectScene());
	game.AddNewScene("room1", new Room1Scene());
    game.AddNewScene("room2", new Room2Scene());
	game.AddNewScene("lose", new LoseScene());
	game.AddNewScene("win", new WinScene());
    game.AddNewScene("how", new HowScene());
	// TODO 1 (1/2): Add a New Scene here and change the start scene below.
    game.AddNewScene("start", new StartScene());
	game.Start("start", 60, 800, 600);
	return 0;
}
