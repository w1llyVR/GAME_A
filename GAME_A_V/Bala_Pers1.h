#pragma once
#include "Personaje.h"
class Bala_Pers1 :
    public Personaje
{
public:
    Bala_Pers1(int x, int y, int w, int h);
    ~Bala_Pers1();
    void mostrar(Bitmap^ img, Graphics^ g);
};

