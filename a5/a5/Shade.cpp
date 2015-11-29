#include "Shade.h"



Shade::Shade(int x, int y, Floor *flr) : Player(x, y, flr)
{
	hp = 125;
	maxHp = 125;
	atk = 25;
	def = 25;
}


Shade::~Shade()
{
}
