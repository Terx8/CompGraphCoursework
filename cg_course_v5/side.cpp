#include "side.h"


int side::det(int _11, float _12, float _21, float _22, float _31, float _32) {
	float x = ((_11 * _22) + (_12 * _31) + (_21 * _32)) -
		((_31 * _22) + (_12 * _21) + (_32 * _11));
	return (x > 0 ? 0 : 1);
}

void side::color(float _xs, float _ys, float _x2, float _y2, float _x3, float _y3, int color) {

	setcolor(color);
	float xs = 0, ys = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	if (_x2 <= _x3)
	{
		if (_xs <= _x2) // xs x2 x3
		{
			xs = _xs; ys = _ys; x2 = _x2;  y2 = _y2; x3 = _x3;  y3 = _y3;
		}
		else
			if (_xs <= _x3) // x2 xs x3
			{
				xs = _x2; ys = _y2; x2 = _xs;  y2 = _ys; x3 = _x3;  y3 = _y3;
			}
			else // x2 x3 xs
			{
				xs = _x2; ys = _y2; x2 = _x3;  y2 = _y3; x3 = _xs;  y3 = _ys;
			}
	}
	else // x3 x2
	{
		if (_xs <= _x3) // xs x3 x2
		{
			xs = _xs; ys = _ys; x2 = _x3;  y2 = _y3; x3 = _x2;  y3 = _y2;
		}
		else
			if (_xs <= _x2) // x3 xs x2
			{
				xs = _x3; ys = _y3; x2 = _xs;  y2 = _ys; x3 = _x2;  y3 = _y2;
			}
			else  // x3 x2 xs
			{
				xs = _x3; ys = _y3; x2 = _x2;  y2 = _y2; x3 = _xs;  y3 = _ys;
			}
	}

	float y1d, y2d;
	float point = xs--;
	point = ceil(point);
	float k1 = ((x2 <= x3 ? y2 : y3) - ys) / ((x2 <= x3 ? x2 : x3) - xs),
		k2 = ((x2 > x3 ? y2 : y3) - ys) / ((x2 > x3 ? x2 : x3) - xs);
	float b1 = (ys - k1 * xs),
		b2 = (ys - k2 * xs);

	while (point <= (x2 < x3 ? x2 : x3))
	{
		y1d = k1 * point + b1;
		if (point == round(xs))
			y1d = ys;

		y2d = k2 * point + b2;
		line(point, ceil(y1d), point, ceil(y2d));
		point++;
	}

	if (x2 != x3)
	{
		k1 = ((x2 >= x3 ? y2 : y3) - (x2 <= x3 ? y2 : y3)) / ((x2 >= x3 ? x2 : x3) - (x2 <= x3 ? x2 : x3));
		b1 = ((x2 < x3 ? y2 : y3) - k1 * (x2 < x3 ? x2 : x3));

		while (point <= (x2 > x3 ? x2 : x3))
		{
			y1d = k1 * (point)+b1;
			if (point == round(xs)) y1d = ys;

			y2d = k2 * point + b2;
			line((point), ceil(y1d), (point), ceil(y2d));
			point++;
		}
	}
}


int side::devideToTriangles() {
	int h = 0, j = 0;
	int m = num;
	int imin = 0, i = 0;
	float diag = 0, min_diag = BIG;
	while (m > 3)
	{
		min_diag = BIG;
		for (i = 0; i < m; i++)
		{
			h = (i == 0 ? m - 1 : i - 1);
			j = (i == m - 1 ? 0 : i + 1);
			diag = (v[h]->x() - v[j]->x()) * (v[h]->x() - v[j]->x()) + (v[h]->y() - v[j]->y()) * (v[h]->y() - v[j]->y());
			if (det(v[h]->x(), v[h]->y(), v[i]->x(), v[i]->y(), v[j]->x(), v[j]->y()) && diag < min_diag)
			{
				imin = i;
				min_diag = diag;
			}
		}
		i = imin;

		h = (i == 0 ? m - 1 : i - 1);
		j = (i == m - 1 ? 0 : i + 1);
		if (min_diag == BIG)
			printf("wrong order\n");

		color(v[i]->x(), v[i]->y(), v[h]->x(), v[h]->y(), v[j]->x(), v[j]->y(), _color);
		m--;
		for (int l = i; l < m; l++)
		{
			v[l]->x(v[l + 1]->x());
			v[l]->y(v[l + 1]->y());
		}
	}

	i = (h == m ? j - 1 : h + 1);

	color(v[i]->x(), v[i]->y(), v[h]->x(), v[h]->y(), v[j]->x(), v[j]->y(), _color);
	return 0;
}


side::side() {	}

side::side(point A, point B, point C, point D, int fc) {
	num = 4;
	v = new point * [4];
	v[0] = new point; *v[0] = A;
	v[1] = new point; *v[1] = B;
	v[2] = new point; *v[2] = C;
	v[3] = new point; *v[3] = D;

	_color = fc;
}

side::side(point A, point B, point C, point D, point E, point F, int fc) {
	num = 6;
	v = new point * [6];
	v[0] = new point; *v[0] = A;
	v[1] = new point; *v[1] = B;
	v[2] = new point; *v[2] = C;
	v[3] = new point; *v[3] = D;
	v[4] = new point; *v[4] = E;
	v[5] = new point; *v[5] = F;

	_color = fc;
}

void side::draw() {
	devideToTriangles();
}

int side::midX() {
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum += v[i]->x();

	return (sum / num);
}
int side::midY() {
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum += v[i]->y();

	return (sum / num);
}
int side::midZ() {
	int sum = 0;
	for (int i = 0; i < num; i++)
		sum += v[i]->z();

	return (sum / num);
}
