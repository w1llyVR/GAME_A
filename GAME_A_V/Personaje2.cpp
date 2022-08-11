#include "Personaje2.h"

Personaje2::Personaje2(Graphics^ g, int w, int h)
{
	this->x = 0;
	this->y = 0;
	this->dx = 5;
	this->w = w;
	this->h = h;
	
}

Personaje2::~Personaje2()
{
}

void Personaje2::mostrar(Graphics^ g, Bitmap^ img)
{
	Rectangle section = Rectangle(w * 3, h * 0, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.2, h * 0.2);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}

void Personaje2::set_dx(int dx)
{
	this->dx = dx;
}

int Personaje2::get_dx()
{
	return this->dx;
}
