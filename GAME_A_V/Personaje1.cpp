#include "Personaje1.h"

Personaje1::Personaje1(int x, int y, int w, int h)
{
	set_x(x);
	set_y(y);
	set_w(w);
	set_h(h);
	dx = 0;
	dy = 0;
	idx = 0;
	idy = 0;
}

Personaje1::~Personaje1()
{
}

void Personaje1::mostrar(Bitmap^ img, Graphics^ g)
{
	Rectangle section = Rectangle(w * idx, h * idy, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.2, h * 0.2);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}

void Personaje1::set_idx(int dx)
{
	this->idx = dx;
}

void Personaje1::set_idy(int dy)
{
	this->idy = dy;
}

int Personaje1::get_idx()
{
	return this->idx;
}

int Personaje1::get_idy()
{
	return this->idy;
}
