#pragma once
#include "Personaje.h"
#include "Balas_Enemigo1.h"
class Enemigo1 :
    public Personaje
{
private:
    int vidas;
    vector<Balas_Enemigo1*>arr;
public:
    Enemigo1(int x, int y, int w, int h);
    ~Enemigo1();
    void mostrar(Bitmap^ img, Graphics^ g);
    int get_vidas();
    void set_vidas(int nuevo);
    vector<Balas_Enemigo1*> get_arr();
    void set_idx(int n);
    void set_idy(int n);
};

