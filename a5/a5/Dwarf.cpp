#include "Dwarf.h"



Dwarf::Dwarf(int x, int y, Floor *floor) : Enemy(x, y, 'W', floor) {
	maxHp = 100;
	hp = 100;
	atk = 20;
	def = 30;
	name = "Dwarf";
}


Dwarf::~Dwarf()
{
}
