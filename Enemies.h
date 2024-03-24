#pragma once
#include "BaseObj.h"
#include "ComFun.h"
#define ENEMIES_H 41;
#define ENEMIES_W 30;


class Enemies : public BaseObject
{
public:
    Enemies();
    ~Enemies();

    void Update (const int &x_bor, const int& y_bor);
    void HandleInput(SDL_Event events);

    void set_x_val(const int& val) {x_val = val;}
    void set_y_val(const int& val) {y_val = val;}
    int get_x_val() const {return x_val;}
    int get_y_val()const {return y_val;}
private:
    int x_val;
    int y_val;

};
