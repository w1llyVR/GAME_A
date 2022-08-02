#include "Controller.h"

void Controller::init(int width, int height, Graphics^ g)
{
	personaje_1 = new Personaje1(0, g->VisibleClipBounds.Bottom - height,   width, height);
}

void Controller::run(Bitmap^ img, Graphics^ g)
{
	personaje_1->mostrar(img, g);
}

void Controller::mover_personaje_1(Graphics^ g, char letra)
{
	if (letra == 'D')
	{
		if (personaje_1->get_x() + 20 <= g->VisibleClipBounds.Width)
			personaje_1->set_x(personaje_1->get_x() + 20);
		personaje_1->set_idx(personaje_1->get_idx() + 1);
		if (personaje_1->get_idx() >= 3) personaje_1->set_idx(0);
		personaje_1->set_idy(2);
	}
	else if (letra == 'A')
	{
		if (personaje_1->get_x() - 20 >= 0)
			personaje_1->set_x(personaje_1->get_x() - 20);
		personaje_1->set_idx(personaje_1->get_idx() + 1);
		if (personaje_1->get_idx() >= 3) personaje_1->set_idx(0);
		personaje_1->set_idy(1);
	}
	else if (letra == 'W')
	{
		if (personaje_1->get_y() - 16 >= 0)
			personaje_1->set_y(personaje_1->get_y() - 16);
		personaje_1->set_idx(personaje_1->get_idx() + 1);
		if (personaje_1->get_idx() >= 3) personaje_1->set_idx(0);
		personaje_1->set_idy(3);
	}
	else if (letra == 'S')
	{
		if (personaje_1->get_y() + 16 <= g->VisibleClipBounds.Width)
			personaje_1->set_y(personaje_1->get_y() + 16);
		personaje_1->set_idx(personaje_1->get_idx() + 1);
		if (personaje_1->get_idx() >= 3) personaje_1->set_idx(0);
		personaje_1->set_idy(0);
	}
}
