#pragma once
#include "ComFun.h"

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

class TextBox {
public:
    TextBox(SDL_Renderer* renderer, TTF_Font* font, int x, int y, SDL_Color color)
        : renderer(renderer), font(font), x(x), y(y), color(color) {}

    // Hàm constructor mặc định
    TextBox() : renderer(nullptr), font(nullptr), x(0), y(0), color({0, 0, 0}) {}

    void Render(int score) {
        SDL_Surface* surface = TTF_RenderText_Solid(font, ("Score: " + std::to_string(score)).c_str(), color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        int text_width = surface->w;
        int text_height = surface->h;

        SDL_Rect dstRect = {x, y, text_width, text_height};
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    int x, y;
    SDL_Color color;
};
