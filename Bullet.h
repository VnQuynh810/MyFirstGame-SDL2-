#pragma once
#include "BaseObj.h"

#define WIDTH_LASER 35
#define HEIGHT_LASER 5

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

class Bullet : public BaseObject
{
public:
     enum BulletType
  {
    NONE = 0,
    LASER = 1,
    SPHERE = 2
  };

    Bullet();
    ~Bullet();

    void HandleInput(SDL_Event events );
    void Update(const int& x_border, const int& y_border);

    int get_type() const {return amo_type;};
    void set_type(const int& type) {amo_type = type;};

    bool get_is_move() const {return is_move;};
    void set_is_move(bool is_move_) {is_move = is_move_;};
    void SetWidthHeight(const int& widht, const int& height) {_rect.w = widht; _rect.h = height;};

private:
    int x_val;
    int y_val;
    bool is_move;
    int amo_type;

};


