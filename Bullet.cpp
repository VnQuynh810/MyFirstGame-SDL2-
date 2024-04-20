#include "Bullet.h"

Bullet::Bullet()
{
    _rect.x = 0;
    _rect.y = 0;
    x_val = 0;
    y_val = 0;
    is_move = false;
    amo_type = NONE;
}

Bullet::~Bullet()
{

}

void Bullet::Update(const int& x_border, const int& y_border)
{
    _rect.y -= 10;
    if (_rect.y > y_border)
    {
        is_move = false;

    }
}

void Bullet::UpdateUpDown()
{
    _rect.y += 6;

    if(_rect.y > SCREEN_HEIGHT)
    {
        is_move = false;
    }
}

void Bullet::HandleInput(SDL_Event events)
{

}

