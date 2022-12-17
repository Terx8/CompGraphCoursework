
#include "paralelepiped.h"

Parallelepiped::Parallelepiped()
{
	side_num = 6;
	point_num = 8;
	shadow_color = 8;

	side_colors[0] = 1;
	side_colors[1] = 2;
	side_colors[2] = 3;
	side_colors[3] = 4;
	side_colors[4] = 5;
	side_colors[5] = 6;

	points = new point[point_num];

	points[A1].set(10, 300, 200, 1);
	points[B1].set(100, 300, 200, 1);
	points[C1].set(100, 300, 0, 1);
	points[D1].set(10, 300, 0, 1);
	points[A2].set(110, 100, 200, 1);
	points[B2].set(200, 100, 200, 1);
	points[C2].set(200, 100, 0, 1);
	points[D2].set(110, 100, 0, 1);
	move(200, 0, 0);
}

void Parallelepiped::painters_alg() 
{
	side** sides = new side * [8];
	sides[0] = new side(points[A1], points[B1], points[C1], points[D1], side_colors[0]);
	sides[1] = new side(points[A2], points[B2], points[C2], points[D2], side_colors[1]);
	sides[2] = new side(points[A1], points[B1], points[B2], points[A2], side_colors[2]);
	sides[3] = new side(points[B1], points[C1], points[C2], points[B2], side_colors[3]);
	sides[4] = new side(points[C1], points[D1], points[D2], points[C2], side_colors[4]);
	sides[5] = new side(points[D1], points[A1], points[A2], points[D2], side_colors[5]);

	int midZ[8] =
	{
		sides[0]->midZ(),
		sides[1]->midZ(),
		sides[2]->midZ(),
		sides[3]->midZ(),
		sides[4]->midZ(),
		sides[5]->midZ()

	};

	int sorted_idx[6] = { 0, 1, 2, 3, 4, 5 };
	double tmp;
	for (int idx = 0; idx < side_num; )
	{
		if ((idx + 1) != side_num && midZ[sorted_idx[idx]] > midZ[sorted_idx[idx + 1]])
		{
			tmp = sorted_idx[idx];
			sorted_idx[idx] = sorted_idx[idx + 1];
			sorted_idx[idx + 1] = tmp;
			idx = 0;
		}
		else idx++;
	}

	for (int i = 0; i < side_num; i++)
		sides[sorted_idx[i]]->draw();

}

void Parallelepiped::draw_shadow() 
{
	double y = 400;
	double x;
	double z;

	calcXY(&points[A1], &x, &z, y);
	point* A1_ = new point(x, y, z);

	calcXY(&points[B1], &x, &z, y);
	point* B1_ = new point(x, y, z);

	calcXY(&points[C1], &x, &z, y);
	point* C1_ = new point(x, y, z);

	calcXY(&points[D1], &x, &z, y);
	point* D1_ = new point(x, y, z);


	calcXY(&points[A2], &x, &z, y);
	point* A2_ = new point(x, y, z);

	calcXY(&points[B2], &x, &z, y);
	point* B2_ = new point(x, y, z);

	calcXY(&points[C2], &x, &z, y);
	point* C2_ = new point(x, y, z);

	calcXY(&points[D2], &x, &z, y);
	point* D2_ = new point(x, y, z);

	A1_->project();
	B1_->project();
	C1_->project();
	D1_->project();

	A2_->project();
	B2_->project();
	C2_->project();
	D2_->project();


	side* shadow[6];

	shadow[0] = new side(*A1_, *B1_, *C1_, *D1_, shadow_color);
	shadow[1] = new side(*A2_, *B2_, *C2_, *D2_, shadow_color);
	shadow[2] = new side(*A1_, *B1_, *B2_, *A2_, shadow_color);
	shadow[3] = new side(*B1_, *C1_, *C2_, *B2_, shadow_color);
	shadow[4] = new side(*C1_, *D1_, *D2_, *C2_, shadow_color);
	shadow[5] = new side(*D1_, *A1_, *A2_, *D2_, shadow_color);

	for (int i = 0; i < 6; i++)
		shadow[i]->draw();

}
