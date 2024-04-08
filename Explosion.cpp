#include "Explosion.h"

Explosion::Explosion()
{

}

Explosion::~Explosion()
{

}


void Explosion::set_clip()
{
    for (int i = 0; i < 6; ++i) {
        frame_clip[i].x = i * EXP_W;
        frame_clip[i].y = 0;
        frame_clip[i].w = EXP_W;
        frame_clip[i].h = EXP_H;
    }
}

void Explosion::ShowEx(SDL_Renderer* des)
{

    if (frame >= 6)
    {
        frame = 0;
    }

    SDL_Rect* current = &frame_clip[frame];
    SDL_Rect renderQuad = {_rect.x,_rect.y,EXP_W,EXP_H};

    SDL_RenderCopy(des, pObject, current,&renderQuad);

}
