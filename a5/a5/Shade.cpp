#include "Shade.h"



Shade::Shade(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 125;
	maxHp = 125;
	atk = 25;
	def = 25;
	chamber = ch;
}


Shade::~Shade()
{
}

void Shade::movement() {

}
