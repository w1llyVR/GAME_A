#include "Bala_Pers1.h"

Bala_Pers1::Bala_Pers1(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->dx = 0;
	this->dy = rand() % (10 - 5 + 1) + 5;
	this->idx = 3;
	this->idy = 1;
}

Bala_Pers1::~Bala_Pers1()
{
}

void Bala_Pers1::mostrar(Bitmap^ img, Graphics^ g)
{
	Rectangle section = Rectangle(w * idx, h * idy, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.1, h * 0.1);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}
