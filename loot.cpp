#include "loot.h"

Loot::Loot()
{
    _rect.x = 0;
    _rect.y = 80;
    _rect.w = loot_w;
    _rect.h = loot_h;
    y_val = 0;
    x_val = 0;
    x_pos = 0;
    y_pos = 0;
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
        x_pos = _rect.x;
        y_pos = _rect.y;
        _rect.x = SCREEN_WIDTH/2;
    }
}






