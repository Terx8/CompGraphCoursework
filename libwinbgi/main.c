#include "..\libwinbgi\src\graphics.h"
void main(void)
{
	initwindow(400, 300);
	moveto(0, 0);
	lineto(50, 50);
	getch();
	closegraph();
}
