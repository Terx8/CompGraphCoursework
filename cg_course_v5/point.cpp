#include "point.h"


double* point::multiply(double M[4][4]) {
	double m[4] = { cor[X], cor[Y], cor[Z], cor[W] };
	double res[4] = { 0, 0, 0, 0 };

	res[X] = m[0] * M[0][0] + m[1] * M[1][0] + m[2] * M[2][0] + m[3] * M[3][0];
	res[Y] = m[0] * M[0][1] + m[1] * M[1][1] + m[2] * M[2][1] + m[3] * M[3][1];
	res[Z] = m[0] * M[0][2] + m[1] * M[1][2] + m[2] * M[2][2] + m[3] * M[3][2];
	res[W] = m[0] * M[0][3] + m[1] * M[1][3] + m[2] * M[2][3] + m[3] * M[3][3];

	cor[X] = res[X];
	cor[Y] = res[Y];
	cor[Z] = res[Z];
	cor[W] = res[W];
	return res;
}


point::point() {	}

point::point(double x, double y, double z)
{
	cor[X] = x;
	cor[Y] = y;
	cor[Z] = z;
	cor[W] = 1;
}

double point::x() {
	return cor[X];
}
void point::x(double _x) {
	cor[X] = _x;
}

double point::y() {
	return cor[Y];
}
void point::y(double _y) {
	cor[Y] = _y;
}

double point::z() {
	return cor[Z];
}
void point::z(double _z) {
	cor[Z] = _z;
}



void point::set(double x, double y, double z, double w) {
	cor[X] = x;	cor[Y] = y;	cor[Z] = z;	cor[W] = w;
}

void point::move_point(double x, double y, double z) {
	double matrix[4][4] = {
		1,  0,  0,  0,	0,  1,  0,  0,	0,  0,  1,  0,	x, y, z, 1 };

	multiply(matrix);
}

void point::scale(double x, double y, double z) {
	double matrix[4][4] = {
		x, 0, 0, 0,	0, y, 0, 0,	0, 0, z, 0,	0, 0, 0, 1 };
	multiply(matrix);
}

void point::rotateX(double phi) {
	phi = phi * 3.1415 / 180;
	double matrix[4][4] = {
		1, 0, 0, 0,	0, cos(phi), -sin(phi), 0,	0, sin(phi), cos(phi),	0, 0, 0, 0, 1 };
	multiply(matrix);
}

void point::rotateY(double phi) {
	phi = phi * 3.1415 / 180;
	double matrix[4][4] = {
		cos(phi), 0, -sin(phi), 0,	0, 1, 0, 0,	sin(phi), 0, cos(phi), 0, 0, 0, 0, 1 };
	multiply(matrix);
}

void point::rotateZ(double phi) {
	phi = phi * 3.1415 / 180;
	double matrix[4][4] = {
		cos(phi), -sin(phi), 0, 0,	sin(phi), cos(phi), 0, 0,	0, 0, 1, 0,	0, 0, 0, 1 };
	multiply(matrix);
}

void point::project() {
	rotateX(30);
	rotateY(-30);
}

void point::unproject() {
	rotateY(30);
	rotateX(-30);
}

