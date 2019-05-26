#include "GameEngine.hpp"
#include "LOG.hpp"
#include "StageSelectScene.hpp"
#include "PlayScene.hpp"
#include "WinScene.hpp"
#include "LoseScene.hpp"
#include "StartScene.hpp"

int main(int argc, char **argv) {
    
    Engine::LOG::SetConfig(true);
    Engine::GameEngine& game = Engine::GameEngine::GetInstance();
    game.AddNewScene("stage-select", new StageSelectScene());
    game.AddNewScene("play", new PlayScene());
    game.AddNewScene("lose", new LoseScene());
    game.AddNewScene("win", new WinScene());
    // TODO 1 (1/2): Add a New Scene here and change the start scene below.
    game.AddNewScene("start", new StartScene());
    game.Start("start", 60, 1600, 832);
    return 0;
}
