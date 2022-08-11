#include "Bala_Disparar.h"

Bala_Disparar::Bala_Disparar(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->dx = 15;
	this->w = w;
	this->h = h;
	this->idx = 3;
	this->idy = 2;
}

Bala_Disparar::~Bala_Disparar()
{
}

void Bala_Disparar::mostrar(Bitmap^ img, Graphics^ g)
{
	Rectangle section = Rectangle(w * idx, h * idy, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.1, h * 0.1);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}
