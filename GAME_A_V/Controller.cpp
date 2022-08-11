#include "Controller.h"

void Controller::init(int width, int height, Graphics^ g)
{
	personaje_1 = new Personaje1(0, g->VisibleClipBounds.Bottom - height,   width, height);
	personaje_2 = new Personaje2(g, width, height);
	enemigo_1 = new Enemigo1(g->VisibleClipBounds.Width - 195, 20, width, height);
	enemigo_2 = new Enemigo1(g->VisibleClipBounds.Width - 195, 20, width, height);
	enemigo_2->set_idx(3);
	enemigo_2->set_idy(4);
	derrotado = false;
	acabo = false;
}

void Controller::run(Bitmap^ img, Graphics^ g)
{
	if (derrotado == false)
	{
		enemigo_1->mostrar(img, g);
		enemigo_1->set_y(enemigo_1->get_y() + enemigo_1->get_dy());
		if (enemigo_1->get_y() <= 20 || enemigo_1->get_y() >= 370)
			enemigo_1->set_dy(enemigo_1->get_dy() * -1);

		//Colision
		for (int i = 0; i < personaje_1->get_arr().size(); i++)
		{
			if (colision(Rectangle(personaje_1->get_arr().at(i)->get_x(), personaje_1->get_arr().at(i)->get_y(), personaje_1->get_arr().at(i)->get_w() - 65, personaje_1->get_arr().at(i)->get_h() - 80),
				Rectangle(enemigo_1->get_x(), enemigo_1->get_y(), enemigo_1->get_w(), enemigo_1->get_h())))
			{
				personaje_1->delete_bala(i);
				enemigo_1->set_vidas(enemigo_1->get_vidas() - 1);
				i = 0;
			}
		}
	}
	else
	{
		enemigo_2->mostrar(img, g);
		enemigo_2->set_y(enemigo_2->get_y() + enemigo_2->get_dy());
		if (enemigo_2->get_y() <= 20 || enemigo_2->get_y() >= 370)
			enemigo_2->set_dy(enemigo_2->get_dy() * -1);

		//Colision
		for (int i = 0; i < personaje_1->get_arr().size(); i++)
		{
			if (colision(Rectangle(personaje_1->get_arr().at(i)->get_x(), personaje_1->get_arr().at(i)->get_y(), personaje_1->get_arr().at(i)->get_w(), personaje_1->get_arr().at(i)->get_h()),
				Rectangle(enemigo_2->get_x(), enemigo_2->get_y(), enemigo_2->get_w(), enemigo_2->get_h())))
			{
				personaje_1->delete_bala(i);
				enemigo_2->set_vidas(enemigo_2->get_vidas() - 1);
				i = 0;
			}
		}
		if (enemigo_2->get_vidas() <= 0) acabo = true;
	}
	
	personaje_1->mostrar(img, g);
	personaje_1->mover_balas(g);
	for (int i = 0; i < personaje_1->get_arr().size(); i++)
	{
		personaje_1->get_arr()[i]->mostrar(img, g);
	}


	if (personaje_2->get_dx() + personaje_2->get_x() > 150 || personaje_2->get_dx() + personaje_2->get_x() < 0) personaje_2->set_dx(personaje_2->get_dx() * -1);
	personaje_2->set_x(personaje_2->get_dx() + personaje_2->get_x());
	personaje_2->mostrar(g, img);
	
	//balas1
	for (int i = 0; i < arr_bala_p1.size(); i++)
	{
		arr_bala_p1[i]->set_y(arr_bala_p1[i]->get_y() + arr_bala_p1[i]->get_dy());
		arr_bala_p1[i]->mostrar(img, g);
	}

	//w- balas
	for (int i = 0; i < arr_bala_p1.size(); i++)
	{
		if (arr_bala_p1[i]->get_y() + 85 >= g->VisibleClipBounds.Bottom - 10)
			arr_bala_p1.erase(arr_bala_p1.begin() + i);
	}

	for (int i = 0; i < arr_bala_p1.size(); i++)
	{
		if (colision(Rectangle(arr_bala_p1.at(i)->get_x(), arr_bala_p1.at(i)->get_y(), 65,  60),
			Rectangle(personaje_1->get_x() , personaje_1->get_y() , 160, 160)))
		{
			arr_bala_p1.erase(arr_bala_p1.begin() + i);
			personaje_1->set_disparos(personaje_1->get_disparos() + 1);
			i = -1;
		}
		
	}

	if (enemigo_1->get_vidas() <= 0)
		derrotado = true;


}

void Controller::mover_personaje_1(Graphics^ g, char letra)
{
	if (letra == 'D')
	{
		if (personaje_1->get_x() + 60 + 20 <= 350)
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
		if (personaje_1->get_y() - 16 >= 85)
			personaje_1->set_y(personaje_1->get_y() - 16);
		personaje_1->set_idx(personaje_1->get_idx() + 1);
		if (personaje_1->get_idx() >= 3) personaje_1->set_idx(0);
		personaje_1->set_idy(3);
	}
	else if (letra == 'S')
	{
		if (personaje_1->get_y() + 85 + 16 < g->VisibleClipBounds.Bottom)
			personaje_1->set_y(personaje_1->get_y() + 16);
		personaje_1->set_idx(personaje_1->get_idx() + 1);
		if (personaje_1->get_idx() >= 3) personaje_1->set_idx(0);
		personaje_1->set_idy(0);
	}
}

void Controller::crear_bala_p1(int width, int height, Graphics^ g)
{
		arr_bala_p1.push_back(new Bala_Pers1(personaje_2->get_x(), personaje_2->get_y() + 85, width, height));
}

void Controller::crear_bala_disparo(int width, int height, Graphics^ g)
{
	if (personaje_1->get_disparos() > 0)
	{
		personaje_1->crea_bala(width, height, g);
		personaje_1->set_disparos(personaje_1->get_disparos() - 1);
	}
}

int Controller::get_n_disparos()
{
	return this->personaje_1->get_disparos();
}

bool Controller::colision(Rectangle a, Rectangle b)
{
	return a.IntersectsWith(b);
}

void Controller::crear_bala_enemigo(int w, int h, Graphics^ g)
{
	enemigo_1->get_arr().push_back(new Balas_Enemigo1(enemigo_1->get_x(),
		enemigo_1->get_y() + 15, enemigo_1->get_w(), enemigo_1->get_h()));
}
