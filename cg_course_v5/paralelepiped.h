#include "../libwinbgi/src/graphics.h"

#include "stdio.h"
#include "figure.h"
#include "side.h"


class Parallelepiped : public figure
{
	int side_colors[6];

public:

	Parallelepiped();
	void painters_alg() override;
	void draw_shadow() override;
};

