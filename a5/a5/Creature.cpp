#include "Creature.h"
#include <cstdlib>
#include <math.h>

//Calls the cell constructor 
Creature::Creature(int x, int y, char sym, Floor *flr) : Cell(x, y, sym, true), floor(flr) { }


Creature::~Creature() {

}

void Creature::loseHp(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		death();
	}
}

void Creature::attack(Creature *defender) {
		int damage = ceil((100 / (100 + defender->getDefense()))*atk);
		defender->loseHp(damage);
	}

int Creature::getDefense() {
	return def;
}

void Creature::death() {

}