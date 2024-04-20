#include "loot.h"

Loot::Loot()
{
    _rect.x = 0;
    _rect.y = 80;
    _rect.w = loot_w;
    _rect.h = loot_h;
    y_val = 0;
    x_val = 0;
    getHit = false;
}


Loot::~Loot()
{

}

void Loot::Update()
{
    _rect.x += x_val;
    if(_rect.x > SCREEN_WIDTH )
    {
        _rect.x = 0;
    }
    if(getHit)
    {
        y_val = _rect.x;
        _rect.x = SCREEN_WIDTH/2;
    }
}






