#include "Balas_Enemigo1.h"

Balas_Enemigo1::Balas_Enemigo1(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->dx = -5;
	this->idx = 3;
	this->idy = 3;

}

Balas_Enemigo1::~Balas_Enemigo1()
{
}

void Balas_Enemigo1::mostrar(Bitmap^ img, Graphics^ g)
{
	Rectangle section = Rectangle(w * idx, h * idy, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.4, h * 0.4);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}
