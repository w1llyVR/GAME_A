#include "Personaje.h"

Personaje::Personaje()
{
}

Personaje::~Personaje()
{
}

void Personaje::set_x(int x)
{
	this->x = x;
}

void Personaje::set_y(int y)
{
	this->y = y;
}

void Personaje::set_w(int w)
{
	this->w = w;
}

void Personaje::set_h(int h)
{
	this->h = h;
}

int Personaje::get_x()
{
	return this->x;
}

int Personaje::get_y()
{
	return this->y;
}

int Personaje::get_w()
{
	return this->w;
}

int Personaje::get_h()
{
	return this->h;
}

void Personaje::mostrar(Bitmap^ img, Graphics^ g)
{
	Rectangle section = Rectangle(w * 0, h * 0, w, h);
	Rectangle zoom = Rectangle(x, y, w * 0.5, h * 0.5);
	g->DrawImage(img, zoom, section, GraphicsUnit::Pixel);
}
