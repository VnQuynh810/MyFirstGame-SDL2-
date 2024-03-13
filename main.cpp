#include <bits/stdc++.h>
#include "ComFun.h"
#include "BaseObj.h"

bool init();
void close();
BaseObject gBackground;
bool LoadBackground();
int main ( int argc, char* args[])
{
   if (init() == false) return -1;
   if (LoadBackground() == false) return -1;


   bool isQuit = false;
   while (!isQuit)
   {
       while (SDL_PollEvent(&gEvent) != 0)
       {
           if (gEvent.type == SDL_QUIT)
           {
               isQuit = true;
           }
       }
       SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR,RENDER_DRAW_COLOR ,RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
       SDL_RenderClear(gScreen);

       gBackground.Render(gScreen, NULL);

       SDL_RenderPresent(gScreen);
   }
    close();
    return 0;
}

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "Space Invader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gScreen = SDL_CreateRenderer( gWindow , -1, SDL_RENDERER_ACCELERATED);
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
            int imgFlags = IMG_INIT_PNG;
            if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) success = false;
        }


        return success;
    }
}

bool LoadBackground ()
{
   bool r = gBackground.LoadImg("pic//background.png",gScreen);
   if (r == false) return false;
   return true;
}

void close()
{
   gBackground.Free();

    SDL_DestroyRenderer(gScreen);
    gScreen = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}
