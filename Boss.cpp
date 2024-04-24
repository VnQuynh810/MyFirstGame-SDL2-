#include "Boss.h"

Boss::Boss()
{
    _rect.x = SCREEN_WIDTH / 2;
    _rect.y = 50;
    _rect.w = BOSS_W;
    _rect.h = BOSS_H;
    y_val = 0;
    x_val = 0;
}
Boss:: ~Boss()
{

}

void Boss::InitBullet(Bullet* bBullet,SDL_Renderer* screen)
{
    if (bBullet)
    {

        bool c = bBullet->LoadImg("pic//GreenBullets.png",screen);
        if(c)
        {
            bBullet->set_is_move(true);
            bBullet->SetRect(GREEN_H,GREEN_W);
            bBullet->SetWidthHeight(GREEN_H,GREEN_W);
            bBullet->set_type(Bullet::GREEN);
            bBullet->SetRect(_rect.x + ENEMIES_W/2,_rect.y);
            bBullet_list.push_back(tBullet);
        }
    }
}

void Enemies::MakeBullet(SDL_Renderer* des, const int& x_limit, const int& y_limit)
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

void Enemies::Update(const int& x_bor, const int &y_bor)
{
    _rect.y += y_val;
    if(_rect.y > BOSS_H)
    {
        y_val = 0;
    }
}



void Boss::ResetBullet(Bullet* bBullet)
{
    bBullet->SetRect(_rect.x + _rect.w/2,_rect.y);

}
