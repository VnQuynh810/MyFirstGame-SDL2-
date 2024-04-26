// Player.cpp
#include "PLayer.h"

Player::Player()
{
    frame = 0;x_val = 0; y_val = 0; width = 0; height = 0; status = -1; _rect.x = SCREEN_WIDTH/2; _rect.y = SCREEN_HEIGHT - SCREEN_HEIGHT/6, lives = 5, shieldActive = false ;
}

Player::~Player() {}

bool Player::LoadImg(std::string path,SDL_Renderer*screen)
{
    bool ret = BaseObject::LoadImg(path,screen);

    if(ret == true)
    {
        width = _rect.w;
        height = _rect.h;
    }
    return ret;
}

void Player::HandleInput(SDL_Event event,SDL_Renderer* screen, Mix_Chunk* shoot_sound) {
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:{
               y_val -= PLAYER_SPEED;
                break;
                }
            case SDLK_DOWN:{
               y_val += PLAYER_SPEED;
                break;
                }
            case SDLK_LEFT:
                x_val -= PLAYER_SPEED;
                break;
            case SDLK_RIGHT:
             x_val += PLAYER_SPEED;
                break;
            case SDLK_w:{
               y_val -= PLAYER_SPEED;
                break;
                }
            case SDLK_s:{
               y_val += PLAYER_SPEED;
                break;
                }
            case SDLK_a:
                x_val -= PLAYER_SPEED;
                break;
            case SDLK_d:
             x_val += PLAYER_SPEED;
                break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                y_val += PLAYER_SPEED;
                break;
            case SDLK_DOWN:
           y_val -= PLAYER_SPEED;
                break;
            case SDLK_LEFT:
           x_val += PLAYER_SPEED;
                break;
          case SDLK_RIGHT:
            x_val -= PLAYER_SPEED;
                break;
            case SDLK_w:
                y_val += PLAYER_SPEED;
                break;
            case SDLK_s:
           y_val -= PLAYER_SPEED;
                break;
            case SDLK_a:
           x_val += PLAYER_SPEED;
                break;
            case SDLK_d:
            x_val -= PLAYER_SPEED;
                break;
        }
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        Bullet* pBullet = new Bullet();
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            pBullet ->SetWidthHeight(WIDTH_LASER,HEIGHT_LASER);
            pBullet->LoadImg("pic//laser.png",screen);
            pBullet ->set_type(Bullet::LASER);
            pBullet->SetRect(this->_rect.x + 38 , this -> _rect.y);
            Mix_PlayChannel(-1,shoot_sound,0);
        }
        else if(event.button.button == SDL_BUTTON_RIGHT)
        {
            pBullet ->SetWidthHeight(WIDTH_SPHERE,HEIGHT_SPHERE);
            pBullet->LoadImg("pic//sphere.png",screen);
            pBullet ->set_type(Bullet::SPHERE);
            pBullet->SetRect(this->_rect.x + 38 , this -> _rect.y);
            Mix_PlayChannel(-1,shoot_sound,0);
        }

        pBullet ->set_is_move(true);

        pBullet_list.push_back(pBullet);
    }
    else if (event.type == SDL_MOUSEBUTTONUP)
    {

    }
}

void Player::Update()
{
    _rect.x += x_val;

    if(_rect.x < 0 || _rect.x + width > SCREEN_WIDTH)
    {
        _rect.x -= x_val;
    }

    _rect.y += y_val;

    if(_rect.y < 0 || _rect.y + height > SCREEN_HEIGHT)
    {
        _rect.y -= y_val;
    }
}

void Player::RemoveBullet(const int& idx)
{
    for(int i = 0; i < pBullet_list.size(); i++)
    {
        if(idx < pBullet_list.size()){
            Bullet* pBullet = pBullet_list.at(idx);
            pBullet_list.erase(pBullet_list.begin() + idx);


            if(pBullet != NULL)
            {
                delete pBullet;
                pBullet = NULL;
            }
        }
    }

}

void Player::IncreaseLives(int amount) {
    lives += amount;
}



