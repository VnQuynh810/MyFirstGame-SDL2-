#include "Game.h"

Game::Game() : gWindow(NULL), gScreen(NULL) {}

Game::~Game() {}

bool Game::Init() {
    if (!InitSDL()) return false;
    gWindow = SDL_CreateWindow("Space Invader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gScreen == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool Game::LoadResources() {
    bool r = gBackground.LoadImg("pic//background.png", gScreen);

    player1.LoadImg("pic//player.png",gScreen);
//    player1.set_clips();
    if (!r) return false;
    return true;
}

void Game::Close() {
    gBackground.Free();
    SDL_DestroyRenderer(gScreen);
    SDL_DestroyWindow(gWindow);
    QuitSDL();
}

void Game::Run() {
    if (!Init()) return;
    if (!LoadResources()) return;


        player1.Update();

        threat1 = new Enemies();
        threat1->LoadImg("pic//Threat1.png",gScreen);
        threat1->set_x_val(5);

    bool isQuit = false;
    while (!isQuit) {
          //  Uint32 startTime = SDL_GetTicks();
        while (SDL_PollEvent(&gEvent) != 0) {
            if (gEvent.type == SDL_QUIT) {
                isQuit = true;
            }

            player1.HandleInput(gEvent,gScreen);
        }
        SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(gScreen);

        gBackground.Render(gScreen, NULL);

        player1.Show(gScreen);
        player1.Update();

          for(int i = 0;i < player1.GetBulletList().size();i++)
        {
            std::vector<Bullet*> bullet_list = player1.GetBulletList();
            Bullet* pBullet = bullet_list.at(i);

            if (pBullet != NULL)
            {
                if (pBullet -> get_is_move())
                {
                    pBullet ->Render(gScreen, NULL);
                    pBullet->Update(SCREEN_WIDTH, SCREEN_HEIGHT);
                }
                else
                {
                    if (pBullet != NULL)
                    {
                        bullet_list.erase(bullet_list.begin()+ i);
                        player1.setBulletList(bullet_list);

                        delete pBullet;
                        pBullet = NULL;
                    }
                }
            }
        }

       threat1->Render(gScreen,NULL);
       threat1->Update(SCREEN_WIDTH,SCREEN_HEIGHT);

        SDL_RenderPresent(gScreen);

       // Uint32 endTime = SDL_GetTicks();
       // Uint32 elapsedTime = endTime - startTime;
       // if (elapsedTime < FRAME_DELAY)
        {
            SDL_Delay(10);
        }
    }
    Close();
}
