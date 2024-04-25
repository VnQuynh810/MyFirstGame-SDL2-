#pragma once
#include "BaseObj.h"
#include "PLayer.h"

enum PowerUpType {
    HEALTH_BOOST = 0,
    POWER_BOOST = 1,
    SHIELD = 2,
};

class PowerUp : public BaseObject {
public:
    PowerUp();
    ~PowerUp();

    void Init(PowerUpType type, SDL_Renderer* screen);
    void ApplyEffect(Player& player);
    void Update();
    int get_type () {return type;}
    bool IsActive() const { return active; }

private:
    PowerUpType type;
    bool active;

};
