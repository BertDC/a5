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

void Goblin::attack(Creature *defender) {
	// Calculates and deals the damage
	double damage = ceil((100 / (100 + defender->getDefense()))*(atk + atkMod));
	// Prints a message
	std::stringstream ss;
	int tempHp = defender->getHp() - damage;
	if (tempHp < 0)
		tempHp = 0;
	ss << " You deal " << damage << " damage to a nearby " << defender->getName() << " (" << tempHp << " HP remaining).";
	if (tempHp == 0) {
		gold += 5;
		ss << " Thanks to your Goblin instincts, you find an additional 5 gold on the corpse.";
		
	}
	floor->actionQueue += ss.str();
	// We do this at the end, in case the Defender is killed in the process
	defender->loseHp(damage);
}

Goblin::~Goblin()
{
}
