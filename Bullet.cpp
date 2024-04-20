#include "Bullet.h"

Bullet::Bullet()
{
    _rect.x = 0;
    _rect.y = 0;
    x_val = 0;
    y_val = 0;
    is_move = false;
    amo_type = NONE;
    angle = 0;
}

Bullet::~Bullet()
{

}

void Bullet::Update(const int& x_border, const int& y_border)
{
    _rect.y -= 3;
    if (_rect.y > y_border)
    {
        is_move = false;

    }
}
/*
void Bullet::sinUpdate(const int& x_border, const int& y_border) {
        angle += 0.1; // Góc tăng dần để di chuyển theo hình sin
        if (angle >= 360) {
            angle = 0; // Reset góc khi đạt giá trị 360 độ
        }

        // Tính toán vị trí mới dựa trên hình sin
        _rect.x += static_cast<int>(5 * std::sin(angle * M_PI / 180));
        _rect.y -= static_cast<int>(7 * std::sin(angle * M_PI / 180));
        if (_rect.y > y_border)
    {
        is_move = false;

    }
}
*/
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

