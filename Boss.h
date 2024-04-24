#pragma once
#include "BaseObj.h"
#include "Bullet.h"
#define BOSS_H 300
#define BOSS_W 300



class Boss : public BaseObject
{
public:
    Boss();
    ~Boss();

    void Update (const int &x_bor, const int& y_bor);
    void HandleInput(SDL_Event events);

    void set_x_val(const int& val) {x_val = val;}
    void set_y_val(const int& val) {y_val = val;}
    int get_x_val() const {return x_val;}
    int get_y_val()const {return y_val;}
    void setBulletList(std::vector<Bullet*> bullet_list) {bBullet_list = bullet_list;};
    std::vector<Bullet*> GetBulletList() const {return bBullet_list;};
    void InitBullet(Bullet* bBullet,SDL_Renderer* gScreen);
    void MakeBullet(SDL_Renderer* des, const int& x_limit, const int& y_limit);
    void Reset(const int& yborder);
    void ResetBullet(Bullet* bBullet);
private:
    int x_val;
    int y_val;
    std::vector<Bullet*> bBullet_list;


};
