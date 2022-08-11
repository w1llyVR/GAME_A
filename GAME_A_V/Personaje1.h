#pragma once
#include "Personaje.h"
#include "Bala_Disparar.h"
class Personaje1 :
    public Personaje
{
private:
    int vida, dx, dy;
    int disparos;
    vector<Bala_Disparar*>arr;
public:
    Personaje1(int x, int y, int w, int h);
    ~Personaje1();
    void mostrar(Bitmap^ img, Graphics^ g);
    void set_idx(int dx);
    void set_idy(int dy);
    void set_disparos(int nuevo);
    int get_idx();
    int get_idy();
    int get_disparos();
    vector<Bala_Disparar*> get_arr();
    void mover_balas(Graphics ^ g);
    void crea_bala(int width, int height, Graphics^ g);
    void delete_bala(int pos) {
        arr.erase(arr.begin() + pos);
    }

};

