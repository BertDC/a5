#include "Drow.h"
#include <cstdlib>
#include <math.h>


Drow::Drow(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 150;
	maxHp = 150;
	atk = 25;
	def = 15;
	name = "Drow";
	chamber = ch;
}


Drow::~Drow()
{
}

bool Drow::consumePotion(std::string dir) {
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
		return false;
	}
	int type = floor->grid[x][y]->getType();
	//Potion effects take place depending on type consumed
	if (type == 0) {
		loseHp(15);
		message = "You feel sick! Lost 15 health.";
	}
	else if (type == 1) {
		hp = fmin(maxHp, hp + 15);
		message = "You feel rejuvenated! Gain +15 health.";
	}
	else if (type == 2) {
		atkMod -= 7.5;
		message = "You feel tired... Lose 7.5 attack.";
	}
	else if (type == 3) {
		atkMod += 7.5;
		message = "You feel stronger!! Gain 7.5 attack!";
	}
	else if (type == 4) {
		defMod -= 7.5;
		message = "You feel weak. Lose 7.5 defense.";
	}
	else if (type == 5) {
		defMod += 7.5;
		message = "You feel your skin harden. Odd. Gain 7.5 defense.";
	}
	else if (type == 6) {
		message = "ERROR";
	}
	//Player will recognize the consumed potion from this point onwards
	knownPots[type] = true;
	delete floor->grid[x][y];
	floor->grid[x][y] = new Cell(x, y, '.');
	return true;
}