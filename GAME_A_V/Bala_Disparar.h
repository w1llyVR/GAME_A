#pragma once
#include "Personaje.h"
class Bala_Disparar :
    public Personaje
{
public:
    Bala_Disparar(int x, int y, int w, int h);
    ~Bala_Disparar();
    void mostrar(Bitmap^ img, Graphics^ g);
};

