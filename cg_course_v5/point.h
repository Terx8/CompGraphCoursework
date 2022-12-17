#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "stdio.h"
#include "math.h"
#include "../libwinbgi/src/graphics.h"

#define X 0
#define Y 1
#define Z 2
#define W 3

class point
{
	double cor[4];

	double* multiply(double M[4][4]);

public:
	point();

	point(double x, double y, double z);

	double x();
	void x(double _x);

	double y();
	void y(double _y);

	double z();
	void z(double _z);


	void set(double x, double y, double z, double w);

	void move_point(double x, double y, double z);

	void scale(double x, double y, double z);

	void rotateX(double phi);

	void rotateY(double phi);

	void rotateZ(double phi);

	void project();

	void unproject();
};
