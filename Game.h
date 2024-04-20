#pragma once
#include "ComFun.h"
#include "BaseObj.h"
#include"PLayer.h"
#include "Enemies.h"
#include "Explosion.h"
#include "Text.h"
#include "loot.h"

#define NUM_THREAT 7

class Game {
public:
    Game();
    ~Game();
    bool Init();
    bool LoadResources();
    void Close();
    void Menu();
    void Run();

private:
    SDL_Window* gWindow;
    SDL_Renderer* gScreen;
    SDL_Event gEvent;
    BaseObject gBackground;
    BaseObject menu;

    Player player1;
    Enemies* threats1 = new Enemies[NUM_THREAT];
    int back_y;
    Explosion p1Boom;
    bool invincible = false;
    Uint32 invincibleTime;

    int score;
    TTF_Font* font;
    TextBox textBox;
    TextBox liveText;

    Loot UFO;
    bool UFOShown = true;
    Uint32 LootShownTime;

    bool isPowerUpActive;
    PowerUp currentPowerUp;

};
