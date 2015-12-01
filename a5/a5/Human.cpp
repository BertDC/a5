#include "Human.h"



Human::Human(int x, int y, Floor *floor) :  Enemy(x, y, 'H', floor)
{
	maxHp = 140;
	hp = 140;
	atk = 20;
	def = 20;
}


Human::~Human()
{
}
