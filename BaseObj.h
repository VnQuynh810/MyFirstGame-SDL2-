#pragma once
#include <bits/stdc++.h>
#include "ComFun.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y) {_rect.x = x, _rect.y = y;}
    SDL_Rect GetRect() const {return _rect;}
    SDL_Texture* GetObject() const {return pObject;}

    bool LoadImg (std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();

protected:
    SDL_Texture* pObject ;
    SDL_Rect _rect;
};

