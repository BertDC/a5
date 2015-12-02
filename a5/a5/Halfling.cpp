#include "Halfling.h"



Halfling::Halfling(int x, int y, Floor *floor) : Enemy(x, y, 'L', floor) {
	maxHp = 100;
	hp = 100;
	atk = 15;
	def = 20;
	name = "Halfling";
}


Halfling::~Halfling()
{
}
