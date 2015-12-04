#include "Dragon.h"
using namespace std;


Dragon::Dragon(int x, int y, Floor * flr, Gold * g) : Enemy(x, y, 'D', flr) {
	maxHp = 150;
	hp = 150;
	atk = 20;
	def = 20;
	name = "Dragon";
	pile = g;
}

// Instead of moving, a Dragon will only attack from its 2-block radius
void Dragon::movement() {
	// If the dragon has already made its turn
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

	// Checks the gold pile radius
	Pos pos = pile->getLocation();
	checkGoldPile(pos.row, pos.col);
}

void Dragon::checkGoldPile(int x, int y) {
	// Determines the symbols of surrounding blocks
	char no = floor->grid[x - 1][y]->getSymbol();
	char so = floor->grid[x + 1][y]->getSymbol();
	char ea = floor->grid[x][y + 1]->getSymbol();
	char we = floor->grid[x][y - 1]->getSymbol();
	char nw = floor->grid[x - 1][y - 1]->getSymbol();
	char ne = floor->grid[x - 1][y + 1]->getSymbol();
	char sw = floor->grid[x + 1][y - 1]->getSymbol();
	char se = floor->grid[x + 1][y + 1]->getSymbol();
	char on = floor->grid[x][y]->getSymbol();

	// If the enemy is within range of the PC, it ATTACKS
	if (se == '@' || ne == '@' || nw == '@' || ea == '@' || we == '@' || so == '@' || no == '@' || sw == '@' || on == '@') {
		// Determines which cell was the Player Character, then attacks it
		if (se == '@') attack(dynamic_cast<Creature*>(floor->grid[x + 1][y + 1]));
		if (sw == '@') attack(dynamic_cast<Creature*>(floor->grid[x + 1][y - 1]));
		if (ne == '@') attack(dynamic_cast<Creature*>(floor->grid[x - 1][y + 1]));
		if (nw == '@') attack(dynamic_cast<Creature*>(floor->grid[x - 1][y - 1]));
		if (we == '@') attack(dynamic_cast<Creature*>(floor->grid[x][y - 1]));
		if (ea == '@') attack(dynamic_cast<Creature*>(floor->grid[x][y + 1]));
		if (so == '@') attack(dynamic_cast<Creature*>(floor->grid[x + 1][y]));
		if (no == '@') attack(dynamic_cast<Creature*>(floor->grid[x - 1][y]));
		if (on == '@') attack(dynamic_cast<Creature*>(floor->grid[x][y]));
		hasMoved = true;
		return;
	}
}

// Overriden death method... Allows for Player to pick up the dragon hoard
void Dragon::death() {
	pile->dragon = NULL;		// The dragon is no longer associated with the gold pile
								
	Cell * hold = floor->grid[posX][posY];	// Makes temporary cell *, swaps and deletes
	floor->grid[posX][posY] = new Cell(posX, posY, '.');
	delete hold;
}

void Enemy::death() {
	
}

Dragon::~Dragon() {

}
