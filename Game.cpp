#include "Game.h"

Game::Game() : gWindow(NULL),gScreen(NULL),back_y(0),score(0),livesCount(5){}

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
    if (TTF_Init()) std::cerr << "iku";
    font = TTF_OpenFont("RobotoMono[wght].ttf",24); // Đường dẫn đến font
        if (!font) {
            std::cerr << "Failed to load font!\n";
        }
        textBox = TextBox(gScreen, font, 10, 10, {255, 255, 255});
    return true;
}

bool Game::LoadResources() {
    bool r = gBackground.LoadImg("pic//background.png", gScreen);

    r = player1.LoadImg("pic//player.png",gScreen);

    p1Boom.LoadImg("pic//Explosion.png",gScreen);
    p1Boom.set_clip();

    //load audio
    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT,2 , 4096) < 0 ) return false;
    g_sound_music = Mix_LoadMUS("audio//music.wav");
    g_sound_bullet = Mix_LoadWAV("audio//playerShoot.wav");
    g_sound_exp = Mix_LoadWAV("audio//Boom.wav");
    g_sound_niceMusic = Mix_LoadMUS("audio//nice-music.wav");

    if (!r) return false;
    return true;
}

void Game::Close() {
    gBackground.Free();
    SDL_DestroyRenderer(gScreen);
    SDL_DestroyWindow(gWindow);
    TTF_CloseFont(font);
    TTF_Quit();
    QuitSDL();
}

void Game::Menu()
{
    if (!Init()) return;
    if (!LoadResources()) return;
    Mix_PlayMusic( g_sound_niceMusic, -1 );
    Mix_VolumeMusic(20);
    SDL_Event e;

    bool isQ = false;
    while(!isQ)
    {

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                isQ = true;
                menu.Free();
            }

        menu.LoadImg("pic//menu.png",gScreen);
        menu.Render(gScreen,NULL);
        SDL_RenderPresent(gScreen);


        if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_x:
                    {
                        isQ = true; menu.Free();
                        break;
                    }

                case SDLK_e:
                    {

                    }
                case SDLK_ESCAPE:
                    {
                        Close(); break;
                    }
                }
            }

        }
    }
}


void Game::Run() {

    Mix_PlayMusic( g_sound_music, -1 );
    Mix_VolumeMusic(50);

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

        while (SDL_PollEvent(&gEvent) != 0) {
            if (gEvent.type == SDL_QUIT) {
                isQuit = true;
            }

            player1.HandleInput(gEvent,gScreen,g_sound_bullet);
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
        textBox.Render(score);


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
                    pBullet->Render(gScreen, NULL);
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

        //xu li trang thai bat tu cua player
        if (invincible)
        {
            Uint32 currentTime = SDL_GetTicks();
            if (currentTime - invincibleTime >= 3000)
            {
                invincible = false; // Kết thúc trạng thái bất tử sau 3 giây
            }
        }
        //xu li doi tuong enemies
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


                    //Check collision threat bullet vs player
                    if(tBullet != NULL)
                    {
                        bool hit = CheckColli(tBullet->GetRect(),player1.GetRect());



                        if(hit&&!invincible)
                        {
                            invincible = true;
                            invincibleTime = SDL_GetTicks();

                            Mix_PlayChannel( -1, g_sound_exp, 0 );
                            //Load explosion animation
                            for(int ex = 0;ex < 6;ex++)
                            {
                                int x_pos = (player1.GetRect().x + player1.GetRect().w/2) - EXP_W/2;
                                int y_pos = (player1.GetRect().y + player1.GetRect().h/2) - EXP_H/2;

                            p1Boom.set_frame(ex);
                            p1Boom.SetRect(x_pos, y_pos);
                            p1Boom.ShowEx(gScreen);
                            SDL_Delay(50);

                            SDL_RenderPresent(gScreen);

                            }


                            player1.SetRect(SCREEN_WIDTH/2, SCREEN_HEIGHT - SCREEN_HEIGHT/6);
                        }
                    }
                }

                //check coll player vs threat
                bool is_col = CheckColli(player1.GetRect(), threat1->GetRect());
                if(is_col)
                {
                    Mix_PlayChannel( -1, g_sound_exp, 0 );
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
                           score++;
                           Mix_PlayChannel( -1, g_sound_exp, 0 );
                           threat1->Reset(SCREEN_HEIGHT - j*500);
                           player1.RemoveBullet(b);
                       }
                    }
                }
            }
        }

        SDL_RenderPresent(gScreen);

        {
            SDL_Delay(10);
        }
    }

    delete[] threats1;

    Close();
}

