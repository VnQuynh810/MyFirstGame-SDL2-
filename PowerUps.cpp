#include "PowerUps.h"

PowerUp::PowerUp() : type(HEALTH_BOOST), active(false) {}

PowerUp::~PowerUp() {}

void PowerUp::Init(PowerUpType type, SDL_Renderer* screen) {
    this->type = type;
    std::string path;

    switch (type) {
        case HEALTH_BOOST:
            path = "pic//Apple.png";
            break;
        case POWER_BOOST:
            path = "pic//appshield.png";
            break;
        case SHIELD:
            path = "pic//shield.png";
            break;
    }

    // Load image
    LoadImg(path, screen);
    std::cout << path;
    active = true;
}

void PowerUp::ApplyEffect(Player& player) {
    if (active) {
        switch (type) {
            case HEALTH_BOOST:
                player.IncreaseLives(5);// Tăng 5 mạng cho Player
                break;
            case POWER_BOOST:
                player.IncreaseLives(5);
                player.shieldActive = true; // Tăng sức mạnh cho Player
                break;
            case SHIELD:
                player.shieldActive = true; // Kích hoạt bảo vệ cho Player
                break;
        }

        active = false;
    }
}

void PowerUp::Update() {
    if (active) {
        // Di chuyển power up xuống
        _rect.y += 2;
        std::cout << _rect.y <<" " << _rect.x << std::endl;
        // Kiểm tra xem power up đã ra khỏi màn hình chưa
        if (_rect.y > SCREEN_HEIGHT - 100) {
            _rect.y -= 2;
        }
    }
}
