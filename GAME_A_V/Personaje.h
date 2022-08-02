#pragma once
using namespace System::Drawing;
class Personaje
{
private:

protected:
	int x, y, w, h, idx, idy;
	void mostrar(Bitmap^ img, Graphics^ g);
public:
	Personaje();
	~Personaje();
	void set_x(int x);
	void set_y(int y);
	void set_w(int w);
	void set_h(int h);
	int get_x();
	int get_y();
	int get_w();
	int get_h();
	
};

