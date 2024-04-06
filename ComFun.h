#pragma once
#include <bits/stdc++.h>
#include <SDL.h>
#include <windows.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

const int FRAME_DELAY = 20;
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 1016;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 1;
const int COLOR_KEY_G = 18;
const int COLOR_KEY_B = 48;

const int RENDER_DRAW_COLOR = 0Xff;


bool InitSDL();
void QuitSDL();
SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path);

typedef struct Input
{
    int left;
    int right;
    int up;
    int down;
} Input;
