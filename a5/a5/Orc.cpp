#include "Orc.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;



Orc::Orc(int x, int y, Floor *floor) : Enemy(x, y, 'O', floor) {
	maxHp = 180;
	hp = 180;
	atk = 30;
	def = 25;
	name = "Orc";
}

void Orc::attack(Creature *defender) {
	stringstream ss;
	// 50% chance of missing
	if (rand() % 2 == 0) {
		ss << " A " << name << " attempts to attack you, but misses!";
		floor->actionQueue += ss.str();
	}
	else {
		double damage;
		if(defender->getName() != "Goblin")
			damage = ceil((100 / (100 + defender->getDefense()))*atk);
		else {
			damage = 1.5*ceil((100 / (100 + defender->getDefense()))*atk);
			ss << " ORC CRUSH PUNY GOBLIN!";
		}
		ss << " You were struck for " << damage << " damage by the " << name << ".";
		floor->actionQueue += ss.str();
		defender->loseHp(damage);
	}
}


Orc::~Orc()
{
}
