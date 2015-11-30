#include "Player.h"
#include <math.h>



Player::Player(int x, int y, int ch, Floor *flr) : Creature(x, y, '@')
{
	atkMod = 0;
	defMod = 0;
	floor = flr;
	chamber = ch;
	prev = '.';
}


Player::~Player()
{
}


void Player::attack(Creature *defender) {
	int damage = ceil((100 / (100 + defender->getDefense()))*(atk + atkMod));
	defender->loseHp(damage);
}

int Player::getDefense() {
	return def + defMod;
}
