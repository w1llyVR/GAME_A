#pragma once
using namespace System::Drawing;
#include <iostream>
using namespace std;
#include <vector>
class Personaje
{
private:

protected:
	int x, y, w, h, idx, idy, dx, dy;
	void mostrar(Bitmap^ img, Graphics^ g);
public:
	Personaje();
	~Personaje();
	void set_x(int x);
	void set_y(int y);
	void set_w(int w);
	void set_h(int h);
	void set_dx(int dx);
	void set_dy(int dy);
	int get_x();
	int get_y();
	int get_w();
	int get_h();
	int get_dx();
	int get_dy();
	
};

