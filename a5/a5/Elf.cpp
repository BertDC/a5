#include "Elf.h"



Elf::Elf(int x, int y, Floor *floor) : Enemy(x, y, 'E', floor) {
	maxHp = 140;
	hp = 140;
	atk = 30;
	def = 10;
	name = "Elf";
}

void Elf::attack(Creature *defender) {
	Enemy::attack(defender);
	if (defender->getName() != "Drow")
		Enemy::attack(defender);
}

Elf::~Elf()
{
}
