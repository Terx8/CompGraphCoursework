#pragma once
#include "../libwinbgi/src/graphics.h"
#include "stdio.h"
#include "point.h"

enum vertexs
{
	A1, B1, C1, D1, A2, B2, C2, D2, E1, F1, E2, F2
};

class figure
{
	protected:

	point* points;
	int point_num;
	int side_num;
	int shadow_color;

	point* L;

	virtual void painters_alg() {};
	virtual void draw_shadow() {};
	double find_midX();
	double find_midY();
	double find_midZ();
	
	void calcXY(point* p, double* x, double* z, int table_y);
	void move(double _x, double _y, double _z);

public:

	figure();

	void up();
	void down();
	void right();
	void left();
	void away();
	void closer();
	void smaller();
	void bigger();
	void rotate(double _phi, int axis);
	void paint();
};