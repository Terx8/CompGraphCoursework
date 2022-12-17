#include "../libwinbgi/src/graphics.h"
#include "figure.h"
#include "prisma6.h"


Prism6::Prism6()
{
	side_num = 8;
	point_num = 12;
	shadow_color = 8;

	side_colors[0] = 1;
	side_colors[1] = 2;
	side_colors[2] = 3;
	side_colors[3] = 4;
	side_colors[4] = 5;
	side_colors[5] = 6;
	side_colors[6] = 7;
	side_colors[7] = 9;

	points = new point[point_num];
	points[A1].set(20, 100, 50, 1);
	points[B1].set(50, 100, 100, 1);
	points[C1].set(100, 100, 100, 1);
	points[D1].set(120, 100, 50, 1);
	points[E1].set(100, 100, 20, 1);
	points[F1].set(50, 100, 20, 1);

	points[A2].set(20, 200, 50, 1);
	points[B2].set(50, 200, 100, 1);
	points[C2].set(100, 200, 100, 1);
	points[D2].set(120, 200, 50, 1);
	points[E2].set(100, 200, 20, 1);
	points[F2].set(50, 200, 20, 1);

	move(400, 0, 0);
}

void Prism6::painters_alg() 
{
	side** sides = new side * [8];
	sides[0] = new side(points[A1], points[B1], points[C1], points[D1], points[E1], points[F1], side_colors[0]);
	sides[1] = new side(points[A2], points[B2], points[C2], points[D2], points[E2], points[F2], side_colors[1]);
	sides[2] = new side(points[A1], points[B1], points[B2], points[A2], side_colors[2]);
	sides[3] = new side(points[B1], points[C1], points[C2], points[B2], side_colors[3]);
	sides[4] = new side(points[C1], points[D1], points[D2], points[C2], side_colors[4]);
	sides[5] = new side(points[D1], points[E1], points[E2], points[D2], side_colors[5]);
	sides[6] = new side(points[E1], points[F1], points[F2], points[E2], side_colors[6]);
	sides[7] = new side(points[F1], points[A1], points[A2], points[F2], side_colors[7]);

	int midZ[8] =
	{
		sides[0]->midZ(),
		sides[1]->midZ(),
		sides[2]->midZ(),
		sides[3]->midZ(),
		sides[4]->midZ(),
		sides[5]->midZ(),
		sides[6]->midZ(),
		sides[7]->midZ()
	};

	int sorted_idx[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
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

void Prism6::draw_shadow()
{
	double y = 400;
	double x = 0;
	double z = 0;

	calcXY(&points[A1], &x, &z, y);		point* A1_ = new point(x, y, z);
	calcXY(&points[B1], &x, &z, y);		point* B1_ = new point(x, y, z);
	calcXY(&points[C1], &x, &z, y);		point* C1_ = new point(x, y, z);
	calcXY(&points[D1], &x, &z, y);		point* D1_ = new point(x, y, z);
	calcXY(&points[E1], &x, &z, y);		point* E1_ = new point(x, y, z);
	calcXY(&points[F1], &x, &z, y);		point* F1_ = new point(x, y, z);
	calcXY(&points[A2], &x, &z, y);		point* A2_ = new point(x, y, z);
	calcXY(&points[B2], &x, &z, y);		point* B2_ = new point(x, y, z);
	calcXY(&points[C2], &x, &z, y);		point* C2_ = new point(x, y, z);
	calcXY(&points[D2], &x, &z, y);		point* D2_ = new point(x, y, z);
	calcXY(&points[E2], &x, &z, y);		point* E2_ = new point(x, y, z);
	calcXY(&points[F2], &x, &z, y);		point* F2_ = new point(x, y, z);

	A1_->project();
	B1_->project();
	C1_->project();
	D1_->project();
	E1_->project();
	F1_->project();
	A2_->project();
	B2_->project();
	C2_->project();
	D2_->project();
	E2_->project();
	F2_->project();

	side* shadow[8];
	shadow[0] = new side(*A1_, *B1_, *C1_, *D1_, *E1_, *F1_, shadow_color);
	shadow[1] = new side(*A2_, *B2_, *C2_, *D2_, *E2_, *F2_, shadow_color);
	shadow[2] = new side(*A1_, *B1_, *B2_, *A2_, shadow_color);
	shadow[3] = new side(*B1_, *C1_, *C2_, *B2_, shadow_color);
	shadow[4] = new side(*C1_, *D1_, *D2_, *C2_, shadow_color);
	shadow[5] = new side(*D1_, *E1_, *E2_, *D2_, shadow_color);
	shadow[6] = new side(*E1_, *F1_, *F2_, *E2_, shadow_color);
	shadow[7] = new side(*F1_, *A1_, *A2_, *F2_, shadow_color);

	for (int i = 0; i < 8; i++)
		shadow[i]->draw();

}

