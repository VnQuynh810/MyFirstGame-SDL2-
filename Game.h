#pragma once
#include "ComFun.h"
#include "BaseObj.h"
#include"PLayer.h"
#include "Enemies.h"
#include "Explosion.h"

#define NUM_THREAT 4

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
    Enemies* threats1 = new Enemies[NUM_THREAT];
    int back_y;
    Explosion p1Boom;
    bool invincible = false;
    Uint32 invincibleTime;
};
