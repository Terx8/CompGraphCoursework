#include "../libwinbgi/src/graphics.h"
#include "stdio.h"
#include "prisma6.h"
#include "paralelepiped.h"


int main()
{
	Parallelepiped* lepiped = new Parallelepiped();
	Prism6* prizm = new Prism6();


	lepiped->smaller();;
	initwindow(1000, 700);

	lepiped->paint();
	prizm->paint();

	char sym;
	while (true)
	{
		sym = getch();
		switch (sym)
		{
		case 'r':	lepiped->rotate(10, 0);		break;
		case 'f':	lepiped->rotate(-10, 0);	break;
		case 't':	lepiped->rotate(10, 1);		break;
		case 'g':	lepiped->rotate(-10, 1);	break;
		case 'c':	lepiped->rotate(10, 2);		break;
		case 'v':	lepiped->rotate(-10, 2);	break;
		case 'z':	lepiped->bigger();			break;
		case 'x':	lepiped->smaller();			break;
		case 'w':	lepiped->up();				break;
		case 's':	lepiped->down();			break;
		case 'a':	lepiped->left();			break;
		case 'd':	lepiped->right();			break;
		case 'q':	lepiped->away();			break;
		case 'e':	lepiped->closer();			break;


		case 'o':	prizm->rotate(10, 0);		break;
		case 'l':	prizm->rotate(-10, 0);		break;
		case 'p':	prizm->rotate(10, 1);		break;
		case ';':	prizm->rotate(-10, 1);		break;
		case 'm':	prizm->rotate(10, 2);		break;
		case ',':	prizm->rotate(-10, 2);		break;
		case 'b':	prizm->bigger();			break;
		case 'n':	prizm->smaller();			break;
		case 'u':	prizm->up();				break;
		case 'j':	prizm->down();				break;
		case 'h':	prizm->left();				break;
		case 'k':	prizm->right();				break;
		case 'y':	prizm->away();				break;
		case 'i':	prizm->closer();			break;

		case '0':
			closegraph();
			return 0;

		}

		clearviewport();
		lepiped->paint();
		prizm->paint();

	}
	getch();
	closegraph();
	return 0;
}
