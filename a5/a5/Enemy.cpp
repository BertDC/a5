#include "Enemy.h"
#include <cstdlib>
#include <ctime>


Enemy::Enemy(int x, int y, char sym, Floor * flr) : Creature(x, y, sym, flr) {

}


Enemy::~Enemy() {

}

void Enemy::death() {
	delete floor->grid[posX][posY];
	floor->grid[posX][posY] = new Gold(posX, posY, (rand() % 2) + 1);
}

void Enemy::movement() {
		//Will move them in any direction or not at all. This whole method is the bogosort of moving algorithms
		int y = posY + (rand() % 3) - 1;
		int x = posX + (rand() % 3) - 1;
		
		//Making the assumption that creatures cannot move between rooms nor stand on items
		if (floor->grid[x][y]->getSymbol() == '.') {
			delete floor->grid[x][y];
			floor->grid[x][y] = floor->grid[posX][posY];
			floor->grid[posX][posY] = new Cell(posX, posY, '.');
			posX = x;
			posY = y;
		}
}
