#pragma once
#include <bits/stdc++.h>
#include <SDL.h>
#include <windows.h>
#include <SDL_mixer.h>
#include <SDL_image.h>


static SDL_Window* gWindow = NULL;
static SDL_Renderer* gScreen = NULL;
static SDL_Event gEvent;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;
static SDL_Surface* gScreenSurface = NULL;
static SDL_Surface* gHelloWorld = NULL;
static SDL_Surface* gXOut = NULL;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0Xff;


bool InitSDL();
void QuitSDL();
SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path);

typedef struct Input ()
{
    int left;
    int right;
    int shoot;
};
