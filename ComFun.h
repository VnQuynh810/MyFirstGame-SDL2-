#pragma once
#include <bits/stdc++.h>
#include <SDL.h>
#include <windows.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

const int FRAME_DELAY = 20;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 900;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 1;
const int COLOR_KEY_G = 18;
const int COLOR_KEY_B = 48;



const int RENDER_DRAW_COLOR = 0Xff;

static Mix_Chunk* g_sound_bullet;
static Mix_Chunk* g_sound_exp;
static Mix_Music* g_sound_music;
static Mix_Chunk* g_sound_powerUp;
static Mix_Music* g_sound_niceMusic;

bool InitSDL();
void QuitSDL();
SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path);


bool CheckColli(const SDL_Rect& object1,const SDL_Rect& object2);
