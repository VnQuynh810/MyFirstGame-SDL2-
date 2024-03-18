#pragma once

#include "ComFun.h"
#include "BaseObj.h"


class player : public BaseObject;
{
public:
    player();
    ~player();

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void ActionInput (SDL_Event input, SDL_Renderer* screen);
private:
    float x_val;
    float y_val;

    float x_pos;
    float y_pos;

    int widthF;
    int heightF;

    SDL_Rect frame_clip[8];
};
