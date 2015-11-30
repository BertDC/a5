#include "Player.h"
#include <math.h>
#include <iostream>
using namespace std;


Player::Player(int x, int y, int ch, Floor *flr) : Creature(x, y, '@', flr) {
	atkMod = 0;
	defMod = 0;
	floor = flr;
	chamber = ch;
	gold = 0;
	actionQueue = "";
	prev = '.';
}


int Player::getChamber() {
	return chamber;
}

Player::~Player() {

}

// Prints the 5 lines of player stats
void Player::printStats() {
	cout << "Race: Shade " << " Gold: " << gold << "                                     Floor: " << floor->getLevel() << endl;
	cout << "HP: " << hp << endl;
	cout << "ATK: " << atk + atkMod << endl;
	cout << "DEF: " << def + defMod << endl;
	cout << "Action: " << actionQueue << endl;
}

// The movement of the Player class
bool Player::movement(string location) {
	if (location == "we") {
		if (floor->grid[posX][posY - 1]->getSymbol() == '.') {
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
		// Player encounters a gold pile
		if (floor->grid[posX][posY - 1]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX][posY - 1]->getType();
			// Dragon gold pile
			if (floor->grid[posX][posY - 1]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX][posY - 1];
			floor->grid[posX][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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
		// Player encounters a gold pile
		if (floor->grid[posX][posY + 1]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX][posY + 1]->getType();
			// Dragon gold pile
			if (floor->grid[posX][posY + 1]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX][posY + 1];
			floor->grid[posX][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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
		// Player encounters a gold pile
		if (floor->grid[posX + 1][posY]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX + 1][posY]->getType();
			// Dragon gold pile
			if (floor->grid[posX + 1][posY]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX + 1][posY];
			floor->grid[posX + 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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
		// Player encounters a gold pile
		if (floor->grid[posX - 1][posY]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX - 1][posY]->getType();
			// Dragon gold pile
			if (floor->grid[posX - 1][posY]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX - 1][posY];
			floor->grid[posX - 1][posY] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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
		// Player encounters a gold pile
		if (floor->grid[posX - 1][posY - 1]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX - 1][posY - 1]->getType();
			// Dragon gold pile
			if (floor->grid[posX - 1][posY - 1]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX - 1][posY - 1];
			floor->grid[posX - 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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
		// Player encounters a gold pile
		if (floor->grid[posX + 1][posY - 1]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX + 1][posY - 1]->getType();
			// Dragon gold pile
			if (floor->grid[posX + 1][posY - 1]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX + 1][posY - 1];
			floor->grid[posX + 1][posY - 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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
		// Player encounters a gold pile
		if (floor->grid[posX - 1][posY + 1]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX - 1][posY + 1]->getType();
			// Dragon gold pile
			if (floor->grid[posX - 1][posY + 1]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX - 1][posY + 1];
			floor->grid[posX - 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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
		// Player encounters a gold pile
		if (floor->grid[posX + 1][posY + 1]->getSymbol() == 'G') {
			// determine size of gold
			int size = floor->grid[posX + 1][posY + 1]->getType();
			// Dragon gold pile
			if (floor->grid[posX + 1][posY + 1]->getType() == 6) {
				return false;
			}
			// If it isnt a dragon hoard, we pick up the gold and move onto its spot
			gold += size;
			delete floor->grid[posX + 1][posY + 1];
			floor->grid[posX + 1][posY + 1] = this;
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
			prev = '.';
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

std::string Player::consumePotion(std::string dir) {
	int x = posX;
	int y = posY;
	string message;
	if (dir == "no" || dir == "ne" || dir == "nw")
		x -= 1;
	else if (dir == "so" || dir == "se" || dir == "sw")
		x += 1;
	if (dir == "ea" || dir == "ne" || dir == "se")
		y += 1;
	else if (dir == "we" || dir == "sw" || dir == "nw")
		y -= 1;
	if (floor->grid[x][y]->getSymbol() != 'P') {
		return "No potion found!";
	}
	int type = floor->grid[x][y]->getType();
	//Potion effects take place depending on type consumed
	if (type == 0) {
		loseHp(10);
		message = "You feel sick! Lost 10 health.";
	}
	else if (type == 1) {
		hp = fmin(maxHp, hp + 10);
		message = "You feel rejuvenated! Gain +10 health.";
	}
	else if (type == 2) {
		atkMod -= 5;
		message = "You feel tired... Lose 5 attack.";
	}
	else if (type == 3) {
		atkMod += 5;
		message = "You feel stronger!! Gain 5 attack!";
	}
	else if (type == 4) {
		defMod -= 5;
		message = "You feel weak. Lose 5 defense.";
	}
	else if (type == 5) {
		defMod += 5;
		message = "You feel your skin harden. Odd. Gain 5 defense.";
	}
	else if (type == 6) {
		message = "One problem down";
	}
	//Player will recognize the consumed potion from this point onwards
	knownPots[type] = true;
	delete floor->grid[x][y];
	floor->grid[x][y] = new Cell(x, y, '.');
	return message;
}

// Gets the player location
Pos Player::getLocation() {
	Pos pos(posX, posY);
	return pos;
}

int Player::getDefense() {
	return def + defMod;
}
