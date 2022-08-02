#pragma once
#include "Personaje.h"
class Personaje1 :
    public Personaje
{
private:
    int vida, dx, dy;
public:
    Personaje1(int x, int y, int w, int h);
    ~Personaje1();
    void mostrar(Bitmap^ img, Graphics^ g);
    void set_idx(int dx);
    void set_idy(int dy);
    int get_idx();
    int get_idy();

};

