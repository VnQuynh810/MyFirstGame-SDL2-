#pragma once

#include "BaseObj.h"
#define BOSS_H 100

class BossObj : public BaseObject
{
public:
    void Update()
    {
            _rect.y += y_val;
        if(_rect.y > BOSS_H )
        {
            y_val = 0;
        }
    }

    void InitBullet(Bullet* tBullet,SDL_Renderer* screen)
{
    if (tBullet)
    {

        bool c = tBullet->LoadImg("pic//GreenBullets.png",screen);
        if(c)
        {
            tBullet->set_is_move(true);
            tBullet->SetRect(GREEN_H,GREEN_W);
            tBullet->SetWidthHeight(GREEN_H,GREEN_W);
            tBullet->set_type(Bullet::GREEN);
            tBullet->SetRect(_rect.x + ENEMIES_W/2,_rect.y);
            tBullet_list.push_back(tBullet);
        }
    }
}

void MakeBullet(SDL_Renderer* des, const int& x_limit, const int& y_limit)
{
    for(int i = 0; i < tBullet_list.size(); i++)
    {
        Bullet* tBullet = tBullet_list.at(i);
        if (tBullet)
        {
            if(tBullet->get_is_move())
            {
                tBullet->Render(des,NULL);
                tBullet->UpdateUpDown();
            }
            else
            {
                tBullet->set_is_move(true);
                tBullet->SetRect(_rect.x + 10,_rect.y + _rect.h/2);
            }
        }
    }
}
};
