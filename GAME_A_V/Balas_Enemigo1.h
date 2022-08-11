#pragma once
#include "Personaje.h"
class Balas_Enemigo1 :
    public Personaje
{
public:
    Balas_Enemigo1(int x, int y, int w, int h);
    ~Balas_Enemigo1();
    void mostrar(Bitmap^ img, Graphics ^ g);

};

