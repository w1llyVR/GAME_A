#include "Enemigo1.h"
#include <vector>

Enemigo1::Enemigo1(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->dx = 0;
	this->dy = 8;
	this->idx = 4;
	this->idy = 0;
	this->vidas = 5;
}

Enemigo1::~Enemigo1()
{
}

void Enemigo1::mostrar(Bitmap^ img, Graphics^ g)
{
	Rectangle section = Rectangle(w * idx, h * idy, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.4, h * 0.4);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}

int Enemigo1::get_vidas()
{
	return this->vidas;
}

void Enemigo1::set_vidas(int nuevo)
{
	this->vidas = nuevo;
}

vector<Balas_Enemigo1*> Enemigo1::get_arr()
{
	return arr;
}

void Enemigo1::set_idx(int n)
{
	this->idx = n;
}

void Enemigo1::set_idy(int n)
{
	this->idy = n;
}
