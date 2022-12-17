#pragma once
#include "../libwinbgi/src/graphics.h"
#include "stdio.h"
#include "point.h"
#define BIG 1.0e30


class side
{
	point** v;
	int _color;
	int num;

	int det(int _11, float _12, float _21, float _22, float _31, float _32);
	void color(float _xs, float _ys, float _x2, float _y2, float _x3, float _y3, int color);
	int devideToTriangles();
	
public:

	side();
	side(point A, point B, point C, point D, int fc);
	side(point A, point B, point C, point D, point E, point F, int fc);
	void draw();

	int midX();
	int midY();
	int midZ();

};