#include "Enemy.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;


Enemy::Enemy(int x, int y, char sym, Floor * flr) : Creature(x, y, sym, flr) {
	hasMoved = false;
	chamber = floor->chamberPos(Pos(x, y));
}


Enemy::~Enemy() {

}



void Enemy::death() {
	// Makes temporary cell *, swaps and deletes
	Cell * hold = floor->grid[posX][posY];
	// For normal enemies, they simply give the player 1 or 2 gold
	floor->giveGold((rand() % 2) + 1);
	floor->grid[posX][posY] = new Cell(posX, posY, '.');
	delete hold;
}

void Enemy::attack(Creature *defender) {
	double damage = ceil((100 / (100 + defender->getDefense()))*atk);
	stringstream ss;
	// 50% chance of missing
	if (rand() % 2 == 0) {
		ss << " A " << name << " attempts to attack you, but misses!";
		floor->actionQueue += ss.str();
	}
	else {
		ss << " You were struck for " << damage << " damage by the " << name << ".";
		floor->actionQueue += ss.str();
		defender->loseHp(damage);
	}
}

// Resets the movement flag, so that we dont move a second time
void Enemy::resetMove() {
	hasMoved = false;
}

void Enemy::movement() {
	// If the enemy has already made its turn
	if (hasMoved) return;

	// Determines the symbols of surrounding blocks
	char no = floor->grid[posX - 1][posY]->getSymbol();
	char so = floor->grid[posX + 1][posY]->getSymbol();
	char ea = floor->grid[posX][posY + 1]->getSymbol();
	char we = floor->grid[posX][posY - 1]->getSymbol();
	char nw = floor->grid[posX - 1][posY - 1]->getSymbol();
	char ne = floor->grid[posX - 1][posY + 1]->getSymbol();
	char sw = floor->grid[posX + 1][posY - 1]->getSymbol();
	char se = floor->grid[posX + 1][posY + 1]->getSymbol();


	// If the enemy is within range of the PC, it ATTACKS instead of moving
	if (se == '@' || ne == '@' || nw == '@' || ea == '@' || we == '@' || so == '@' || no == '@' || sw == '@') {
			// Determines which cell was the Player Character, then attacks it
			if (se == '@') attack(dynamic_cast<Creature*>(floor->grid[posX + 1][posY + 1]));
			if (sw == '@') attack(dynamic_cast<Creature*>(floor->grid[posX + 1][posY - 1]));
			if (ne == '@') attack(dynamic_cast<Creature*>(floor->grid[posX - 1][posY + 1]));
			if (nw == '@') attack(dynamic_cast<Creature*>(floor->grid[posX - 1][posY - 1]));
			if (we == '@') attack(dynamic_cast<Creature*>(floor->grid[posX][posY - 1]));
			if (ea == '@') attack(dynamic_cast<Creature*>(floor->grid[posX][posY + 1]));
			if (so == '@') attack(dynamic_cast<Creature*>(floor->grid[posX + 1][posY]));
			if (no == '@') attack(dynamic_cast<Creature*>(floor->grid[posX - 1][posY]));
		hasMoved = true;
		return;
	}

	// Checks if there is at least one valid move for the enemy to go to. If there is, it randomly moves, if not, nothing happens
	if (se != '.' && ne != '.' && nw != '.' && ea != '.' && we != '.' && so != '.' && no != '.' && sw != '.') {
		return;
	}

	// This will be called if there is a valid space for the creature to move to
	while (true) {
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
