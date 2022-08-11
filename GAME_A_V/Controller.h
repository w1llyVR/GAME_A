#pragma once
#include "./Personaje1.h"
#include "./Personaje2.h"
#include "./Bala_Pers1.h"
#include "./Enemigo1.h"
using namespace System::Drawing;
class Controller
{
private:
	Personaje1* personaje_1;
	Personaje2* personaje_2;
	vector<Bala_Pers1*> arr_bala_p1;
	Enemigo1* enemigo_1;
	Enemigo1* enemigo_2;
	bool derrotado;
	bool acabo;
public:
	void init(int width, int height, Graphics ^ g);
	void run(Bitmap ^ img, Graphics ^ g);
	void mover_personaje_1(Graphics^ g, char letra);
	void crear_bala_p1(int width, int height, Graphics ^ g);
	void crear_bala_disparo(int width, int height, Graphics^ g);
	int get_n_disparos();
	bool colision(Rectangle a, Rectangle b);
	void crear_bala_enemigo(int w, int h, Graphics^ g);
	bool get_acabo() { return acabo; }
};

