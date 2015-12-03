#include "Troll.h"
#include <math.h>
using namespace std;


Troll::Troll(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 120;
	maxHp = 120;
	atk = 25;
	def = 15;
	name = "Troll";
	chamber = ch;
}


Troll::~Troll()
{
}

void Troll::attack(Creature *defender){
	Player::attack(defender);
	hp = fmin(hp+5, maxHp);
}

bool Troll::movement(std::string location) {
	bool moved = Player::movement(location);
	if (moved)
		hp = fmin(hp + 5, maxHp);
	return moved;
}

bool Troll::consumePotion(std::string dir) {
	bool consumed = Player::consumePotion(dir);
	if (consumed) {
		hp = fmin(hp + 5, maxHp);
	}
	return consumed;
	
}

void Troll::resetModifiers() {
	Player::resetModifiers();
	hp = fmin(hp + 5, maxHp);
}
