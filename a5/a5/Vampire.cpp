#include "Vampire.h"



Vampire::Vampire(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 50;
	maxHp = 0;
	atk = 25;
	def = 25;
	chamber = ch;
}


Vampire::~Vampire()
{
}

void Vampire::attack(Creature *defender) {
	int damage = ceil((100 / (100 + defender->getDefense()))*(atk + atkMod));
	if (defender->getSymbol() == 'L') {
		if (rand() % 2 == 1) {
			defender->loseHp(damage);
			hp += 5;
		}
	}
	else {
		defender->loseHp(damage);
		hp += 5;
	}
}

std::string Vampire::consumePotion(std::string dir) {
	int x = posX;
	int y = posY;
	std::string message;
	if (dir == "no" || dir == "ne" || dir == "nw")
		x -= 1;
	else if (dir == "so" || dir == "se" || dir == "sw")
		x += 1;
	if (dir == "ea" || dir == "ne" || dir == "se")
		y += 1;
	else if (dir == "we" || dir == "sw" || dir == "nw")
		y -= 1;
	if (floor->grid[x][y]->getSymbol() != 'P') {
		return "No potion found!";
	}
	int type = floor->grid[x][y]->getType();
	//Potion effects take place depending on type consumed
	if (type == 0) {
		loseHp(10);
		message = "You feel sick! Lost 10 health.";
	}
	else if (type == 1) {
		hp = hp + 10;
		message = "You feel rejuvenated! Gain +10 health.";
	}
	else if (type == 2) {
		atkMod -= 5;
		message = "You feel tired... Lose 5 attack.";
	}
	else if (type == 3) {
		atkMod += 5;
		message = "You feel stronger!! Gain 5 attack!";
	}
	else if (type == 4) {
		defMod -= 5;
		message = "You feel weak. Lose 5 defense.";
	}
	else if (type == 5) {
		defMod += 5;
		message = "You feel your skin harden. Odd. Gain 5 defense.";
	}
	else if (type == 6) {
		message = "ERROR";
	}
	//Player will recognize the consumed potion from this point onwards
	knownPots[type] = true;
	delete floor->grid[x][y];
	floor->grid[x][y] = new Cell(x, y, '.');
	return message;
}
