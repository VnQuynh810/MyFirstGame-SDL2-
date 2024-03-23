// Player.cpp
#include "PLayer.h"

Player::Player()
{
    frame = 0;x_val = 0; y_val = 0; width = 0; height = 0; status = -1;
}

Player::~Player() {}

bool Player::LoadImg(std::string path,SDL_Renderer*screen)
{
    bool ret = BaseObject::LoadImg(path,screen);

    if(ret == true)
    {
        width = _rect.w/4;
        height = _rect.h;
    }
    return ret;
}

/* void Player::set_clips()
{
    if (width > 0 & height > 0)
    {
        for (int i = 0; i < 4; ++i) {
        frame_clip[i].x = i * width;
        frame_clip[i].y = 0;
        frame_clip[i].w = width;
        frame_clip[i].h = height;
    }

    }
} */

void Player::Show(SDL_Renderer* des) {

   LoadImg ("pic//Dove",des);

/*   if (input_type.up == 1 ||input_type.down == 1){frame++;} else {frame =0;}

   if(frame >= 4)
   {
       frame = 0;
   }
*/


 // SDL_Rect* current = &frame_clip[frame];
 SDL_Rect renderQuad = {_rect.x,_rect.y,width,height};

 //  SDL_RenderCopy(des,pObject,current,&renderQuad);
    int i = 0;
    frame_clip[i].x = i * width;
        frame_clip[i].y = 0;
        frame_clip[i].w = width;
        frame_clip[i].h = height;
 SDL_RenderCopy (des,pObject,&frame_clip[i],&renderQuad);
}

void Player::HandleInput(SDL_Event event,SDL_Renderer* screen) {
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:{

               input_type.up = 1;
               y_val -= PLAYER_SPEED;
                break;
                }
            case SDLK_DOWN:{
                input_type.down = 1;
               y_val += PLAYER_SPEED;
                break;
                }
            case SDLK_LEFT:
                x_val -= PLAYER_SPEED;
                break;
            case SDLK_RIGHT:
             x_val += PLAYER_SPEED;
                break;
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                y_val += PLAYER_SPEED;
            //    input_type.up = 0;

                break;
            case SDLK_DOWN:
           y_val -= PLAYER_SPEED;
      //     input_type.down = 0;
                break;
            case SDLK_LEFT:
           x_val += PLAYER_SPEED;
                break;
          case SDLK_RIGHT:
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
        }
        else if(event.button.button == SDL_BUTTON_RIGHT)
        {
            pBullet ->SetWidthHeight(WIDTH_SPHERE,HEIGHT_SPHERE);
            pBullet->LoadImg("pic//sphere.png",screen);
            pBullet ->set_type(Bullet::SPHERE);
        }
        pBullet->SetRect(this->_rect.x + 10 , this -> _rect.y - 10);
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

