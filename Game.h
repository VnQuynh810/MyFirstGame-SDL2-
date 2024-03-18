#pragma once
#include "ComFun.h"
#include "BaseObj.h"

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
};
