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
	disparos = 10;
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

void Personaje1::set_disparos(int nuevo)
{
	this->disparos = nuevo;
}

int Personaje1::get_idx()
{
	return this->idx;
}

int Personaje1::get_idy()
{
	return this->idy;
}

int Personaje1::get_disparos()
{
	return this->disparos;
}

vector<Bala_Disparar*> Personaje1::get_arr()
{
	return arr;
}

void Personaje1::mover_balas(Graphics ^ g)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i]->set_x(arr[i]->get_x() + arr[i]->get_dx());
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i]->get_x() >= g->VisibleClipBounds.Width - 10)
			arr.erase(arr.begin() + i);
	}
}

void Personaje1::crea_bala(int width, int height, Graphics^ g)
{
	arr.push_back(new Bala_Disparar(this->x + 60, this->y + 10, width, height));
}
