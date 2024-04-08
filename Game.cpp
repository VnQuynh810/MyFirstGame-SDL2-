#include "Game.h"

Game::Game() : gWindow(NULL), gScreen(NULL),back_y(0) {}

Game::~Game() {}

bool Game::Init() {
    if (!InitSDL()) return false;
    gWindow = SDL_CreateWindow("Space Invader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        std::cout << "Window could not be created! SDL_Error: "<< SDL_GetError();
        return false;
    }
    gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gScreen == NULL) {
        std::cout <<"Renderer could not be created! SDL Error: " << SDL_GetError();
        return false;
    }
    return true;
}

bool Game::LoadResources() {
    bool r = gBackground.LoadImg("pic//background.png", gScreen);

    r = player1.LoadImg("pic//player.png",gScreen);

    p1Boom.LoadImg("pic//Explosion.png",gScreen);
    p1Boom.set_clip();

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

    for(int i = 0; i < NUM_THREAT;i++)
    {
        Enemies* threat1 = (threats1 + i);
        bool r =  threat1->LoadImg("pic//Threat1.png",gScreen);
        if(r == false) return;

        int rand_x = rand()%800;
        if(rand_x > SCREEN_WIDTH)
        {
            rand_x = SCREEN_WIDTH*0.2;
        }

        threat1->SetRect(rand_x,SCREEN_HEIGHT - i*500);
        threat1->set_y_val(2);

        Bullet* tBullet = new Bullet();
        threat1->InitBullet(tBullet,gScreen);
    }

    bool isQuit = false;
    while (!isQuit) {
        //  Uint32 startTime = SDL_GetTicks();
        while (SDL_PollEvent(&gEvent) != 0) {
            if (gEvent.type == SDL_QUIT) {
                isQuit = true;
            }

            player1.HandleInput(gEvent,gScreen);
        }
        SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);//Make background of the image transparent
        SDL_RenderClear(gScreen);

        back_y += 1;
        gBackground.SetRect(NULL,back_y);
        gBackground.Render(gScreen, NULL);
        gBackground.SetRect(NULL,back_y - SCREEN_HEIGHT);
        gBackground.Render(gScreen,NULL);

        if(back_y >= SCREEN_HEIGHT)
        {
            back_y = 0;
        }

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

        for(int j = 0;j < NUM_THREAT;j++)
        {
            Enemies* threat1 = (threats1 + j);
            if(threat1)
            {
                threat1->Update(SCREEN_WIDTH,SCREEN_HEIGHT);
                threat1->Render(gScreen,NULL);

                threat1->MakeBullet(gScreen,SCREEN_HEIGHT,SCREEN_WIDTH);


                std::vector<Bullet*> tbullet_list = threat1->GetBulletList();
                for (int b = 0; b < tbullet_list.size(); b++)
                {
                    Bullet* tBullet = tbullet_list.at(b);

                    if(tBullet != NULL)
                    {
                        bool hit = CheckColli(tBullet->GetRect(),player1.GetRect());
                        if(hit)
                        {
                            player1.SetRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - SCREEN_HEIGHT/6);
                        }
                    }
                }

                bool is_col = CheckColli(player1.GetRect(), threat1->GetRect());
                if(is_col)
                {
                    for(int ex = 0;ex < 6;ex++)
                    {
                        int x_pos = (player1.GetRect().x + player1.GetRect().w/2) - EXP_W/2;
                        int y_pos = (player1.GetRect().y + player1.GetRect().h/2) - EXP_H/2;

                        p1Boom.set_frame(ex);
                        p1Boom.SetRect(x_pos, y_pos);
                        p1Boom.ShowEx(gScreen);
                        SDL_Delay(100);

                        SDL_RenderPresent(gScreen);

                    }

                    if( MessageBoxW(NULL, L"GAME OVER!", L"Info", MB_OK) == IDOK)
                    {
                        delete[] threats1;
                        Close();
                        return;
                    }
                }

                std::vector<Bullet*> bullet_list = player1.GetBulletList();
                for (int b = 0; b < bullet_list.size(); b++)
                {
                    Bullet* pBullet = bullet_list.at(b);

                    if(pBullet != NULL)
                    {
                        bool rc = CheckColli(pBullet->GetRect(),threat1->GetRect());
                       if(rc)
                       {
                           threat1->Reset(SCREEN_HEIGHT - j*500);
                           player1.RemoveBullet(b);
                       }
                    }
                }
            }
        }

        SDL_RenderPresent(gScreen);

        // Uint32 endTime = SDL_GetTicks();
        // Uint32 elapsedTime = endTime - startTime;
        // if (elapsedTime < FRAME_DELAY)
        {
            SDL_Delay(10);
        }
    }

    delete[] threats1;

    Close();
}

