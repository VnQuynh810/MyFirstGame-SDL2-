#pragma once
#include "ComFun.h"
#include "BaseObj.h"
#include"PLayer.h"
#include "Enemies.h"

class Game {
public:
    Game();
    ~Game();
    bool Init();
    bool LoadResources();
    void Close();
    void Run();

private:
    SDL_Window* gWindow;
    SDL_Renderer* gScreen;
    SDL_Event gEvent;
    BaseObject gBackground;
    Player player1;
    Enemies* threat1;
};
