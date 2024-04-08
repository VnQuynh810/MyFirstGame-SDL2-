#pragma once

#include "BaseObj.h"
#include "ComFun.h"

const int EXP_W = 89;
const int EXP_H = 90;
class Explosion : public BaseObject
{
public:
    Explosion();
    ~Explosion();
    void set_clip();
    void set_frame(const int& fr) {frame = fr;}
    void ShowEx(SDL_Renderer* des);
private:
    int frame;
    SDL_Rect frame_clip[6];


};




