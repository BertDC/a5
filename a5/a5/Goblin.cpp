#include "Goblin.h"



Goblin::Goblin(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 110;
	maxHp = 110;
	atk = 15;
	def = 20;
	name = "Goblin";
	chamber = ch;
}


Goblin::~Goblin()
{
}
