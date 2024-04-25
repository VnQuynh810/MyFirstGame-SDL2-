
#pragma once

#include "BaseObj.h"
#include "PowerUps.h"

#define loot_w 60
#define loot_h 46

class Loot : public BaseObject
{
public:
    Loot();
    ~Loot();

    void Update();
    SDL_Rect GetRect() const { return _rect; }
    int x_val;
    int y_val;
    int x_pos;
    int y_pos;
    bool getHit;
};

