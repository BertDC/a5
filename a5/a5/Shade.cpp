#include "Shade.h"
using namespace std;


Shade::Shade(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 125;
	maxHp = 125;
	atk = 25;
	def = 25;
	chamber = ch;
}


Shade::~Shade() {

}

// Moves the Shade 
void Shade::movement(string location) {
	if (location == "no") {
		if (floor->grid[posX][posY - 1]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX][posY - 1];
			floor->grid[posX][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, '.');
			prev = '.';
			posX = posX;
			posY = posY - 1;
		}
	}
	else if (location == "so") {

	}
	else if (location == "ea") {

	}
	else if (location == "we") {

	}
	else if (location == "nw") {

	}
	else if (location == "ne") {

	}
	else if (location == "sw") {

	}
	else if (location == "se") {

	}
}
