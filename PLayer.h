// Player.h
#pragma once

#include "BaseObj.h"
#include "Bullet.h"
class Player : public BaseObject {
public:
    Player();
    ~Player();
    void Show(SDL_Renderer* des);
    bool LoadImg(std::string path,SDL_Renderer* screen);
    void HandleInput(SDL_Event event,SDL_Renderer* screen,Mix_Chunk* shoot_sound);
    void set_clips();
    void Update();
    void IncreaseLives(int amount);

    void setBulletList(std::vector<Bullet*> bullet_list) {pBullet_list = bullet_list;};
    std::vector<Bullet*> GetBulletList() const {return pBullet_list;};
    void RemoveBullet(const int& idx);

    int get_live() {return lives;}

   bool shieldActive;

private:
    static const int PLAYER_SPEED = 5;
    int x_val, y_val;
    int x_pos, y_pos;
    int height, width;
    int frame;
    int status;
    SDL_Rect frame_clip[8];
    std::vector<Bullet*> pBullet_list;

    int lives;
    int power;

    Uint32 shieldDuration;

};
