#include <bits/stdc++.h>
#include "BaseObj.h"

BaseObject::BaseObject()
{
    pObject = NULL;
    _rect.x = 0;
    _rect.y = 0;
    _rect.w = 0;
    _rect.h = 0;
}
BaseObject::~BaseObject()
{
    Free();
}
bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;

    SDL_Surface* load_surface = IMG_Load(path.c_str());

    if(load_surface != NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format,COLOR_KEY_R,COLOR_KEY_G,COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);

        if (new_texture != NULL) {
            _rect.w = load_surface ->w;
            _rect.h = load_surface ->h;
        }
        pObject = new_texture;
        return pObject != NULL;
    }
}

void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip )
{
    SDL_Rect renderquad = {_rect.x, _rect.y,_rect.w,_rect.h};

    SDL_RenderCopy(des, pObject,clip, &renderquad);
}

void BaseObject::Free()
{
    if(pObject != NULL)
    {
        SDL_DestroyTexture(pObject);
        pObject = NULL;
        _rect.w = 0;
        _rect.h = 0;
    }
}
