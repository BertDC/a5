#include "Goblin.h"



Goblin::Goblin(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 120;
	maxHp = 120;
	atk = 25;
	def = 15;
	name = "Goblin";
	chamber = ch;
}


Goblin::~Goblin()
{
}
