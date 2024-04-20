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
    if(tBullet_list.size() > 0);
    {
        for(int i = 0; i < tBullet_list.size(); i++)
        {
            Bullet* tBullet = tBullet_list.at(i);
            if(tBullet != NULL)
            {
                delete tBullet;
                tBullet = NULL;
            }
        }
        tBullet_list.clear();
    }
}

void Enemies::InitBullet(Bullet* tBullet,SDL_Renderer* screen)
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
    if(_rect.y > SCREEN_HEIGHT )
    {
        _rect.y = 0;
        int rand_x = rand()%1000;
        if(rand_x > SCREEN_WIDTH)
        {
            rand_x = SCREEN_WIDTH*0.2;
        }
        _rect.x = rand_x;
    }
}

void Enemies::Reset(const int& yborder)
{
    _rect.y = yborder;
    _rect.y = SCREEN_HEIGHT;

    int rand_x = rand()%400;
        if(rand_x > SCREEN_WIDTH)
        {
            rand_x = SCREEN_WIDTH*0.2;
        }
        _rect.x = rand_x;

        for (int i = 0; i < tBullet_list.size();i++)
        {
            Bullet* tBullet = tBullet_list.at(i);

            if(tBullet)
            {
                ResetBullet(tBullet);
            }
        }

}

void Enemies::ResetBullet(Bullet* tBullet)
{
    tBullet->SetRect(_rect.x + _rect.w/2,_rect.y);

}
