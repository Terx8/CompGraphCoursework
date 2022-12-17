#include "../libwinbgi/src/graphics.h"
#include "stdio.h"
#include "figure.h"
#include "side.h"



class Prism6 : public figure
{
	int side_colors[8];

public:

	Prism6();

	void painters_alg() override;

	void draw_shadow() override;
};

