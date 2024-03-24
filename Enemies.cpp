#include "Enemies.h"

Enemies::Enemies()
{
    _rect.x = SCREEN_WIDTH / 2;
    _rect.y = 50;
    _rect.w = ENEMIES_W;
    _rect.h = ENEMIES_H;
    y_val = 0;
    x_val = 0;
}
Enemies:: ~Enemies()
{

}

void Enemies::Update(const int& x_bor, const int &y_bor)
{
    _rect.x -= x_val;
    if(_rect.x < 0)
    {
        _rect.x = SCREEN_WIDTH;
    }
}

