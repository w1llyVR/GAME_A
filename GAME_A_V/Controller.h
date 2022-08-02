#pragma once
#include "./Personaje1.h"
using namespace System::Drawing;
class Controller
{
private:
	Personaje1* personaje_1;
public:
	void init(int width, int height, Graphics ^ g);
	void run(Bitmap ^ img, Graphics ^ g);
	void mover_personaje_1(Graphics^ g, char letra);



};

