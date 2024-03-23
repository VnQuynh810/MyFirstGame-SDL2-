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
    void HandleInput(SDL_Event event,SDL_Renderer* screen);
    void set_clips();
    void Update();

   
private:
    static const int PLAYER_SPEED = 5;
    int x_val, y_val;
    int x_pos, y_pos;
    int height, width;
    Input input_type;
    int frame;
    int status;
    SDL_Rect frame_clip[8];
   
};
