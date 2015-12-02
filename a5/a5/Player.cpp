#include "Player.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;


Player::Player(int x, int y, int ch, Floor *flr) : Creature(x, y, '@', flr) {
	atkMod = 0;
	defMod = 0;
	floor = flr;
	chamber = ch;
	gold = 0;
	prev = '.';
	for (int i = 0; i < 5; i++) {
		knownPots[i] = false;
	}
	aggroMerch = false;
}


int Player::getChamber() {
	return chamber;
}

Player::~Player() {

}

// Prints the 5 lines of player stats
void Player::printStats() {
	cout << "Race: " << name << " Gold: " << gold << "                                                  Floor: " << floor->getLevel() + 1 << endl;
	cout << "HP: " << hp << endl;
	cout << "ATK: " << atk + atkMod << endl;
	cout << "DEF: " << def + defMod << endl;
	cout << "Action:" << floor->actionQueue << endl;
	// Resets the list of actions
	floor->actionQueue = "";
}

// The movement of the Player class
bool Player::movement(string dir) {
	int x = posX;
	int y = posY;
	if (dir == "no" || dir == "ne" || dir == "nw")
		x -= 1;
	else if (dir == "so" || dir == "se" || dir == "sw")
		x += 1;
	if (dir == "ea" || dir == "ne" || dir == "se")
		y += 1;
	else if (dir == "we" || dir == "sw" || dir == "nw")
		y -= 1;

	if (floor->grid[x][y]->getSymbol() == '.') {
		// creates the old tile the Player was on and swaps location
		delete floor->grid[x][y];
		floor->grid[x][y] = this;
		// Checks to see if we were previously on a dragon hoard
		if (prev == 'G')
			floor->grid[posX][posY] = dHoard;
		else 
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
		// Updates the previous tile and position
		prev = '.';
		posX = x;
		posY = y;
		return true;
	}
	if (floor->grid[x][y]->getSymbol() == '+') {
		// creates the old tile the Player was on and swaps location
		delete floor->grid[x][y];
		floor->grid[x][y] = this;
		// Checks to see if we were previously on a dragon hoard
		if (prev == 'G')
			floor->grid[posX][posY] = dHoard;
		else
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
		// Updates the previous tile and position
		prev = '+';
		posX = x;
		posY = y;
		return true;
	}
	if (floor->grid[x][y]->getSymbol() == '#') {
		// creates the old tile the Player was on and swaps location
		delete floor->grid[x][y];
		floor->grid[x][y] = this;
		// Checks to see if we were previously on a dragon hoard
		if (prev == 'G')
			floor->grid[posX][posY] = dHoard;
		else
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
		// Updates the previous tile and position
		prev = '#';
		posX = x;
		posY = y;
		return true;
	}
	// Player encounters a gold pile
	if (floor->grid[x][y]->getSymbol() == 'G') {
		// determine size of gold
		int size = floor->grid[x][y]->getType();
		// Dragon gold pile
		if (floor->grid[x][y]->getType() == 6) {
			Gold * hold = dynamic_cast<Gold*>(floor->grid[x][y]);
			// If there is still a dragon attatched to the hoard, then we cant pick up
			if (hold->dragon) {
				// Checks to see if we were previously on a dragon hoard
				if (prev == 'G')
					floor->grid[posX][posY] = dHoard;
				else
					floor->grid[posX][posY] = new Cell(posX, posY, prev);
				dHoard = hold;
				floor->grid[x][y] = this;
				prev = 'G';
				posX = x;
				posY = y;
				stringstream ss;
				ss << " You're standing on a dragon's hoard, and it's still alive!";
				floor->actionQueue += ss.str();
				return true;
			}
			else {	// The dragon has been slain!
				gold += size;
				delete floor->grid[x][y];
				floor->grid[x][y] = this;
				// Checks to see if we were previously on a dragon hoard
				if (prev == 'G')
					floor->grid[posX][posY] = dHoard;
				else
					floor->grid[posX][posY] = new Cell(posX, posY, prev);
				prev = '.';
				posX = x;
				posY = y;
				stringstream ss;
				ss << " You pick up " << size << " gold from the Dragon's treasury.";
				floor->actionQueue += ss.str();
				return true;
			}
			return true;
		}
		// If it isnt a dragon hoard, we pick up the gold and move onto its spot
		gold += size;
		delete floor->grid[x][y];
		floor->grid[x][y] = this;
		// Checks to see if we were previously on a dragon hoard
		if (prev == 'G')
			floor->grid[posX][posY] = dHoard;
		else
			floor->grid[posX][posY] = new Cell(posX, posY, prev);
		prev = '.';
		posX = x;
		posY = y;
		stringstream ss;
		ss << " You pick up " << size << " gold.";
		floor->actionQueue += ss.str();
		return true;
	}
	// Player encounters the stairs
	if (floor->grid[x][y]->getSymbol() == '\\') {
		return true;
	}
	// Player can't make a move
	return false;
}


void Player::death() {
	floor->actionQueue += "You have perished.";
	displayScore();
	floor->setAlive(false);
	floor->actionQueue += "Press 'q' to exit or 'r' to try again.";
}

void Player::displayScore() {
	stringstream ss;
	ss << endl << "Your run has ended. You achieved a score of " << gold << "." << endl;;
	floor->actionQueue += ss.str();
}


void Player::attack(Creature *defender) {
	// Calculates and deals the damage
	double damage = ceil((100 / (100 + defender->getDefense()))*(atk + atkMod));
	// Prints a message
	stringstream ss;
	int tempHp = defender->getHp() - damage;
	if (tempHp < 0) tempHp = 0;
	ss << " You deal " << damage << " damage to a nearby " << defender->getName() << " (" << tempHp << " HP remaining).";
	floor->actionQueue += ss.str();
	// We do this at the end, in case the Defender is killed in the process
	defender->loseHp(damage);
}

// Called from the floor class to attempt a strike
bool Player::attemptStrike(string dir) {
	int x = posX;
	int y = posY;
	if (dir == "no" || dir == "ne" || dir == "nw")
		x -= 1;
	else if (dir == "so" || dir == "se" || dir == "sw")
		x += 1;
	if (dir == "ea" || dir == "ne" || dir == "se")
		y += 1;
	else if (dir == "we" || dir == "sw" || dir == "nw")
		y -= 1;
	char symbol = floor->grid[x][y]->getSymbol();
	if (symbol != 'D' && symbol != 'H' && symbol != 'L' && symbol != 'E' && symbol != 'W' && symbol != 'M' && symbol != 'O') {
		return false;
	}
	// attacking a Merchant
	else if (symbol == 'M') {
		aggroMerch = true;
		attack(dynamic_cast<Creature*>(floor->grid[x][y]));
		return true;
	}
	// attacking a Halfling
	else if (symbol == 'L') {
		// 50% chance to miss
		if (rand() % 2 == 0) {
			floor->actionQueue += " You miss the Halfling!";
		}
		else {
			attack(dynamic_cast<Creature*>(floor->grid[x][y]));
			return true;
		}
	}
	// for any other class
	else {
		attack(dynamic_cast<Creature*>(floor->grid[x][y]));
		return true;
	}
}

bool Player::consumePotion(string dir) {
	int x = posX;
	int y = posY;
	if (dir == "no" || dir == "ne" || dir == "nw")
		x -= 1;
	else if (dir == "so" || dir == "se" || dir == "sw")
		x += 1;
	if (dir == "ea" || dir == "ne" || dir == "se")
		y += 1;
	else if (dir == "we" || dir == "sw" || dir == "nw")
		y -= 1;
	if (floor->grid[x][y]->getSymbol() != 'P') {
		return false;
	}
	int type = floor->grid[x][y]->getType();
	//Potion effects take place depending on type consumed
	if (type == 0) {
		loseHp(10);
		floor->actionQueue += " You feel sick! Lost 10 health.";
	}
	else if (type == 1) {
		hp = fmin(maxHp, hp + 10);
		floor->actionQueue += " You feel rejuvenated! Gain +10 health.";
	}
	else if (type == 2) {
		atkMod -= 5;
		floor->actionQueue += " You feel tired... Lose 5 attack.";
	}
	else if (type == 3) {
		atkMod += 5;
		floor->actionQueue += " You feel stronger! Gain 5 attack!";
	}
	else if (type == 4) {
		defMod -= 5;
		floor->actionQueue += " You feel weak. Lose 5 defense.";
	}
	else if (type == 5) {
		defMod += 5;
		floor->actionQueue += " You feel your skin harden. Odd. Gain 5 defense.";
	}
	else if (type == 6) {
		floor->actionQueue += " ERROR";
	}
	//Player will recognize the consumed potion from this point onwards
	knownPots[type] = true;
	delete floor->grid[x][y];
	floor->grid[x][y] = new Cell(x, y, '.');
	return true;
}

void Player::giveGold(int x) {
	gold += x;
}

double Player::getDefense() {
	return def + defMod;
}

bool Player::getAggroMerch() {
	return aggroMerch;
}

void Player::interactVicinity() {
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++) {
			char sym = floor->grid[posX + i][posY + j]->getSymbol();
			if (sym == 'P') {
				int type = floor->grid[posX + i][posY + j]->getType();
				if (knownPots[type] == true) {
					if (type == 0)
						floor->actionQueue += " You spot a Poison Health potion.";
					else if (type == 1)
						floor->actionQueue += " You spot a Restore Health potion.";
					else if (type == 2)
						floor->actionQueue += " You spot a Weaken Attack potion.";
					else if (type == 3)
						floor->actionQueue += " You spot a Boost Attack potion.";
					else if (type == 4)
						floor->actionQueue += " You spot a Weaken Defense potion.";
					else if (type == 5)
						floor->actionQueue += " You spot a Boost Defense potion.";

				}
				else
					floor->actionQueue += " You spot an unknown potion.";
			}
		}
}
