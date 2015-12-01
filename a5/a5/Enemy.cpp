#include "Enemy.h"
#include <iostream>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;


Enemy::Enemy(int x, int y, char sym, Floor * flr) : Creature(x, y, sym, flr) {
	hasMoved = false;
}


Enemy::~Enemy() {

}

void Enemy::death() {
	delete floor->grid[posX][posY];
	floor->grid[posX][posY] = new Gold(posX, posY, (rand() % 2) + 1);
}

void Enemy::attack(Creature *defender) {
	double damage = ceil((100 / (100 + defender->getDefense()))*atk);
	defender->loseHp(damage);
}

// Resets the movement flag, so that we dont move a second time
void Enemy::resetMove() {
	hasMoved = false;
}

void Enemy::movement() {
	// Checks if there is at least one valid move for the enemy to go to. If there is, it randomly moves, if not, nothing happens
	if (floor->grid[posX + 1][posY + 1]->getSymbol() != '.' && floor->grid[posX - 1][posY + 1]->getSymbol() != '.'
		&& floor->grid[posX - 1][posY - 1]->getSymbol() != '.' && floor->grid[posX][posY + 1]->getSymbol() != '.'
		&& floor->grid[posX][posY - 1]->getSymbol() != '.' && floor->grid[posX + 1][posY]->getSymbol() != '.'
		&& floor->grid[posX - 1][posY]->getSymbol() != '.') {
		return;
	}

	// This will be called if there is a valid space for the creature to move to
	while (!hasMoved) {
		//Will move them in any direction or not at all. This whole method is the bogosort of moving algorithms
		int y = posY + (rand() % 3 - 1);
		int x = posX + (rand() % 3 - 1);
		
		//Making the assumption that creatures cannot move between rooms nor stand on items
		if (floor->grid[x][y]->getSymbol() == '.') {
			delete floor->grid[x][y];
			floor->grid[x][y] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, '.');
			posX = x;
			posY = y;
			break;
		}
	}
	hasMoved = true;
}
