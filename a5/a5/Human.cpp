#include "Human.h"
#include "Gold.h"
#include <cstdlib>
using namespace std;

Human::Human(int x, int y, Floor *floor) :  Enemy(x, y, 'H', floor) {
	maxHp = 140;
	hp = 140;
	atk = 20;
	def = 20;
	name = "Human";
}

// The Human's custom death method (spawns 2 piles of gold)
void Human::death() {
	// Makes temporary cell *, swaps and deletes
	cout << "posX value: " << posX << "   posY value: " << posY << endl;
	Human * hold = dynamic_cast<Human *>(floor->grid[posX][posY]);
	// Makes the first pile of gold where the human was
	int x = posX;
	int y = posY;
	Floor *flr = floor;
	floor->grid[posX][posY] = new Gold(posX, posY, 2);
	delete hold;
	// Makes the second pile of gold in the nearest area
	makeGold(x, y, flr);
}

// Attempts to make a gold pile around the given coordinates
void Human::makeGold(int x, int y, Floor *floor) {
	cout << "posX value: " << posX << "   posY value: " << posY << endl;
	// Determines the symbols of surrounding blocks
	char no = floor->grid[x - 1][y]->getSymbol();
	char so = floor->grid[x + 1][y]->getSymbol();
	char ea = floor->grid[x][y + 1]->getSymbol();
	char we = floor->grid[x][y - 1]->getSymbol();
	char nw = floor->grid[x - 1][y - 1]->getSymbol();
	char ne = floor->grid[x - 1][y + 1]->getSymbol();
	char sw = floor->grid[x + 1][y - 1]->getSymbol();
	char se = floor->grid[x + 1][y + 1]->getSymbol();

	// If we can't find a valid location then we try the next vicinity
	if (se != '.' && ne != '.' && nw != '.' && ea != '.' && we != '.' && so != '.' && no != '.' && sw != '.') {
		makeGold(x + (rand() % 2 - 1), y + (rand() % 2 - 1), floor);
		return;
	}

	// There is at least one '.' tile, so we randomly make one of them into a gold pile
	while (true) {
		//Randomly selects a tile in the vicinity
		int x2 = x + (rand() % 3 - 1);
		int y2 = y + (rand() % 3 - 1);

		// If a '.' is found, makes a gold
		if (floor->grid[x2][y2]->getSymbol() == '.') {
			Cell * hold =  floor->grid[x2][y2];
			floor->grid[x2][y2] = new Gold(x2, y2, 2);
			delete hold;
			break;
		}
	}
}


Human::~Human() {

}
