#pragma once
#include "BaseObj.h"
#include "PLayer.h"

enum PowerUpType {
    HEALTH_BOOST,
    POWER_BOOST,
    SHIELD
};

class PowerUp : public BaseObject {
public:
    PowerUp();
    ~PowerUp();

    void Init(PowerUpType type, SDL_Renderer* screen);
    void ApplyEffect(Player& player);
    void Update();
    PowerUpType Get() {return type;}
    bool IsActive() const { return active; }

private:
    PowerUpType type;
    bool active;

};
