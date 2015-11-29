#include "Creature.h"
#include <cstdlib>
#include <math.h>

//Calls the cell constructor 
Creature::Creature(int x, int y, char sym) : Cell(x, y, sym, true)
{
}


Creature::~Creature()
{
}

void Creature::loseHp(int damage) {
	hp -= damage;
	if (hp <= 0)
		death();
}

void Creature::attack(Creature *defender) {
		int damage = ceil((100 / (100 + defender->getDefense()))*atk);
		defender->loseHp(damage);
	}

int Creature::getDefense() {
	return def;
}

void Creature::movement() {
	//We need to discuss how creature movement works again. For this method to work then creatures need access to the Cell array
	while (true) {
		break;
		//Will move them in any direction or not at all. This whole method is the bogosort of moving algorithms
		int y = posX + (rand() % 3) - 1;
		int x = posY + (rand() % 3) - 1;
		/*
		//Making the assumption that creatures cannot move between rooms nor stand on items
		if (cellArray[x][y].symbol == '.'){
		delete cellArray[x][y];
		cellArray[x][y] = cellArray[posX][posY];
		cellArray[posX][posY] == new cell(posX, posY, '.');
		posX = x;
		posY = y;

		}
		*/
		
	}
}

void Creature::death() {

}