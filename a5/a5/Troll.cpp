#include "Troll.h"



Troll::Troll(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 120;
	maxHp = 120;
	atk = 25;
	def = 15;
	chamber = ch;
}


Troll::~Troll()
{
}

void Troll::attack(Creature *defender){
	Player::attack(defender);
	hp += 5;
}

bool Troll::movement(std::string location) {
	bool moved = Player::movement(location);
	if (moved)
		hp += 5;
	return moved;
}

std::string Troll::consumePotion(std::string dir) {
	hp += 5;
	return Player::consumePotion(dir);
	
}
