#include "Player.h"
#include <math.h>
#include <iostream>
using namespace std;


Player::Player(int x, int y, int ch, Floor *flr) : Creature(x, y, '@', flr)
{
	atkMod = 0;
	defMod = 0;
	floor = flr;
	chamber = ch;
	prev = '.';
}


int Player::getChamber() {
	return chamber;
}

Player::~Player()
{
}

bool Player::movement(string location) {
	if (location == "we") {
		if (floor->grid[posX][posY - 1]->getSymbol() == '.') {
			cout << "moving to ." << endl;
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX][posY - 1];
			floor->grid[posX][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX;
			posY = posY - 1;
			return true;
		}
		if (floor->grid[posX][posY - 1]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX][posY - 1];
			floor->grid[posX][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX;
			posY = posY - 1;
			return true;
		}
		if (floor->grid[posX][posY - 1]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX][posY - 1];
			floor->grid[posX][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX;
			posY = posY - 1;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX][posY - 1]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	else if (location == "ea") {
		if (floor->grid[posX][posY + 1]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX][posY + 1];
			floor->grid[posX][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX;
			posY = posY + 1;
			return true;
		}
		if (floor->grid[posX][posY + 1]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX][posY + 1];
			floor->grid[posX][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX;
			posY = posY + 1;
			return true;
		}
		if (floor->grid[posX][posY + 1]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX][posY + 1];
			floor->grid[posX][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX;
			posY = posY + 1;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX][posY + 1]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	else if (location == "so") {
		if (floor->grid[posX + 1][posY]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY];
			floor->grid[posX + 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX + 1;
			posY = posY;
			return true;
		}
		if (floor->grid[posX + 1][posY]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY];
			floor->grid[posX + 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX + 1;
			posY = posY;
			return true;
		}
		if (floor->grid[posX + 1][posY]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY];
			floor->grid[posX + 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX + 1;
			posY = posY;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX + 1][posY]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	else if (location == "no") {
		if (floor->grid[posX - 1][posY]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY];
			floor->grid[posX - 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX - 1;
			posY = posY;
			return true;
		}
		if (floor->grid[posX - 1][posY]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY];
			floor->grid[posX - 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX - 1;
			posY = posY;
			return true;
		}
		if (floor->grid[posX - 1][posY]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY];
			floor->grid[posX - 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX - 1;
			posY = posY;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX - 1][posY]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	else if (location == "nw") {
		if (floor->grid[posX - 1][posY - 1]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY - 1];
			floor->grid[posX - 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX - 1;
			posY = posY - 1;
			return true;
		}
		if (floor->grid[posX - 1][posY - 1]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY - 1];
			floor->grid[posX - 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX - 1;
			posY = posY - 1;
			return true;
		}
		if (floor->grid[posX - 1][posY - 1]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY - 1];
			floor->grid[posX - 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX - 1;
			posY = posY - 1;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX - 1][posY - 1]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	else if (location == "sw") {
		if (floor->grid[posX + 1][posY - 1]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY - 1];
			floor->grid[posX + 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX + 1;
			posY = posY - 1;
			return true;
		}
		if (floor->grid[posX + 1][posY - 1]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY - 1];
			floor->grid[posX + 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX + 1;
			posY = posY - 1;
			return true;
		}
		if (floor->grid[posX + 1][posY - 1]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY - 1];
			floor->grid[posX + 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX + 1;
			posY = posY - 1;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX + 1][posY - 1]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	else if (location == "ne") {
		if (floor->grid[posX - 1][posY + 1]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY + 1];
			floor->grid[posX - 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX - 1;
			posY = posY + 1;
			return true;
		}
		if (floor->grid[posX - 1][posY + 1]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY + 1];
			floor->grid[posX - 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX - 1;
			posY = posY + 1;
			return true;
		}
		if (floor->grid[posX - 1][posY + 1]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX - 1][posY + 1];
			floor->grid[posX - 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX - 1;
			posY = posY + 1;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX - 1][posY + 1]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	else if (location == "se") {
		if (floor->grid[posX + 1][posY + 1]->getSymbol() == '.') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY + 1];
			floor->grid[posX + 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '.';
			posX = posX + 1;
			posY = posY + 1;
			return true;
		}
		if (floor->grid[posX + 1][posY + 1]->getSymbol() == '+') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY + 1];
			floor->grid[posX + 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '+';
			posX = posX + 1;
			posY = posY + 1;
			return true;
		}
		if (floor->grid[posX + 1][posY + 1]->getSymbol() == '#') {
			// creates the old tile the Player was on and swaps location
			delete floor->grid[posX + 1][posY + 1];
			floor->grid[posX + 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			// Updates the previous tile and position
			prev = '#';
			posX = posX + 1;
			posY = posY + 1;
			return true;
		}
		// Player encounters the stairs
		if (floor->grid[posX + 1][posY + 1]->getSymbol() == '\\') {
			return true;
		}
		// Player can't make a move
		return false;
	}
	return false;
}


void Player::attack(Creature *defender) {
	int damage = ceil((100 / (100 + defender->getDefense()))*(atk + atkMod));
	defender->loseHp(damage);
}

int Player::getDefense() {
	return def + defMod;
}
