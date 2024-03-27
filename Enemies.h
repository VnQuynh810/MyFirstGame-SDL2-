#pragma once
#include "BaseObj.h"
#include "ComFun.h"
#include "Bullet.h"
#define ENEMIES_H 41;
#define ENEMIES_W 30;


class Enemies : public BaseObject
{
public:
    Enemies();
    ~Enemies();

    void Update (const int &x_bor, const int& y_bor);
    void HandleInput(SDL_Event events);

    void set_x_val(const int& val) {x_val = val;}
    void set_y_val(const int& val) {y_val = val;}
    int get_x_val() const {return x_val;}
    int get_y_val()const {return y_val;}
    void setBulletList(std::vector<Bullet*> bullet_list) {tBullet_list = bullet_list;};
    std::vector<Bullet*> GetBulletList() const {return tBullet_list;};
    void InitBullet(Bullet* tBullet,SDL_Renderer* gScreen);
    void MakeBullet(SDL_Renderer* des, const int& x_limit, const int& y_limit);
private:
    int x_val;
    int y_val;
    std::vector<Bullet*> tBullet_list;


};
