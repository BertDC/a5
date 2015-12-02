#include "Merchant.h"
#include "Player.h"
using namespace std;


Merchant::Merchant(int x, int y, Floor *floor) : Enemy(x, y, 'M', floor) {
	maxHp = 30;
	hp = 30;
	atk = 70;
	def = 5;
	name = "Merchant";
}

void Merchant::death() {
	// Makes temporary cell *, swaps and deletes
	Cell * hold = floor->grid[posX][posY];
	floor->grid[posX][posY] = new Gold(posX, posY, 4);
	delete hold;
}

void Merchant::movement() {
	//Enemy::movement();
	//return;
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


	// If the enemy is within range of the PC, it ATTACKS instead of moving. Checks for Merchant hostility
	if (floor->getPlayerHostile() && (se == '@' || ne == '@' || nw == '@' || ea == '@' || we == '@' || so == '@' || no == '@' || sw == '@')) {
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

Merchant::~Merchant()
{
}
