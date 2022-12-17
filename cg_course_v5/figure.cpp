#include "figure.h"

double figure::find_midX()
{
	double s = 0;
	for (int i = 0; i < point_num; i++)
		s += points[i].x();

	s /= (double)point_num;
	return s;
}
double figure::find_midY()
{
	double s = 0;
	for (int i = 0; i < point_num; i++)
		s += points[i].y();

	s /= (double)point_num;
	return s;
}
double figure::find_midZ()
{
	double s = 0;
	for (int i = 0; i < point_num; i++)
		s += points[i].z();

	s /= (double)point_num;
	return s;
}

void figure::calcXY(point* p, double* x, double* z, int table_y)
{
	double t = (table_y - p->y()) / (L->y() - p->y());
	*x = (L->x() - p->x()) * t + p->x();
	*z = (L->z() - p->z()) * t + p->z();
}

void figure::move(double _x, double _y, double _z)
{
	for (int i = 0; i < point_num; i++)
		points[i].move_point(_x, _y, _z);
}



figure::figure()
{
	L = new point(400, 0, 0);
}


void figure::up()
{
	for (int i = 0; i < point_num; i++)
		points[i].move_point(0, -60, 0);
}

void figure::down()
{
	for (int i = 0; i < point_num; i++)
		points[i].move_point(0, 60, 0);
}

void figure::right()
{
	for (int i = 0; i < point_num; i++)
		points[i].move_point(60, 0, 0);
}

void figure::left()
{
	for (int i = 0; i < point_num; i++)
		points[i].move_point(-60, 0, 0);
}


void figure::away()
{
	for (int i = 0; i < point_num; i++)
		points[i].move_point(0, 0, -60);
}

void figure::closer()
{
	for (int i = 0; i < point_num; i++)
		points[i].move_point(0, 0, 60);
}


void figure::smaller()
{
	double midX = find_midX(),
		midY = find_midY(),
		midZ = find_midZ();

	move(-midX, -midY, -midZ);

	double k = 0.5;
	for (int i = 0; i < point_num; i++)
		points[i].scale(k, k, k);


	move(midX, midY, midZ);
}


void figure::bigger()
{
	double midX = find_midX(),
		midY = find_midY(),
		midZ = find_midZ();

	move(-midX, -midY, -midZ);

	double k = 2;
	for (int i = 0; i < point_num; i++)
		points[i].scale(k, k, k);

	move(midX, midY, midZ);
}


void figure::rotate(double _phi, int axis)
{

	double midX = find_midX(),
		midY = find_midY(),
		midZ = find_midZ();

	move(-midX, -midY, -midZ);


	switch (axis)
	{
	case X:
		for (int i = 0; i < point_num; i++)
			points[i].rotateX(_phi);
		break;
	case Y:
		for (int i = 0; i < point_num; i++)
			points[i].rotateY(_phi);

		break;
	case Z:
		for (int i = 0; i < point_num; i++)
			points[i].rotateZ(_phi);

		break;
	}

	move(midX, midY, midZ);
}

void figure::paint()
{
	draw_shadow();

	for (int i = 0; i < point_num; i++)
		points[i].project();

	painters_alg();
	for (int i = 0; i < point_num; i++)
		points[i].unproject();

}
