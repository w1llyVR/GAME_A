#pragma once
#include "Personaje.h"
class Personaje2 :
    public Personaje
{
private:
    int dx;
public:
    Personaje2(Graphics^ g, int w, int h);
    ~Personaje2();
    void mostrar(Graphics^ g, Bitmap^ img);
    void set_dx(int dx);
    int get_dx();
};

