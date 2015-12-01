#include "Floor.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Human.h"
#include "cell.h"
#include "Gold.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// The Position class
Pos::Pos(int x, int y) : row(x), col(y) { }
Pos::~Pos() { }

// The only constructor
Floor::Floor(int level) : level(level), grid(NULL), player(NULL), alive(true), actionQueue("") { }

// Deletes ALL cells in the grid, then deletes the grid itself
Floor::~Floor() {
	for (int row = 0; row < 25; row++) {
		for (int col = 0; col < 79; col++) {
			delete grid[row][col];
		}
		delete grid[row];
	}
	delete grid;
}

int Floor::getLevel() { return level; }

// Adds the neighbours of a Cell to the chamber if required
void Floor::addNeighbours(int row, int col, int chamber) {
	// Goes through 4 neighbours and adds them the chamber if it can
	char c1 = grid[row + 1][col]->getSymbol();
	char c2 = grid[row - 1][col]->getSymbol();
	char c3 = grid[row][col + 1]->getSymbol();
	char c4 = grid[row][col - 1]->getSymbol();
	if (c1 != '|' && c1 != '-' && c1 != ' ' && c1 != '#' && c1 != '+') {
		addToChamber(row + 1, col, chamber);
	}
	if (c2 != '|' && c2 != '-' && c2 != ' ' && c2 != '#' && c2 != '+') {
		addToChamber(row - 1, col, chamber);
	}
	if (c3 != '|' && c3 != '-' && c3 != ' ' && c3 != '#' && c3 != '+') {
		addToChamber(row, col + 1, chamber);
	}
	if (c4 != '|' && c4 != '-' && c4 != ' ' && c4 != '#' && c4 != '+') {
		addToChamber(row, col - 1, chamber);
	}
}

// Adds the position of a Cell to the Chamber if it has not already been added
void Floor::addToChamber(int row, int col, int chamber) {
	if (grid[row][col]->inChamber) return;		// This cell is already part of a chamber
	// Otherwise...
	Pos * position = new Pos(row, col);
	chambers[chamber].push_back(*position);			// adds the position to the Chamber
	grid[row][col]->inChamber = true;

	// Now we add the neighbours
	addNeighbours(row, col, chamber);
}

// Starts the process to make the 5 chambers.
void Floor::makeChambers() {
	int chamber = 0;
	for (int row = 0; row < 25; row++) {
		for (int col = 0; col < 79; col++) {
			// If we find a floor tile that is not currently part of a chamber, add it to that chamber;
			if (grid[row][col]->getSymbol() == '.' && !grid[row][col]->inChamber) {
				addToChamber(row, col, chamber);
				chamber++;  // The next empty tile we find will be part of the next chamber.
			}
		}
	}
}

// Sets up the floor
void Floor::initialize(string race, Controller *c, fstream *file) {
	controller = c;		// Allows this Floor to access the Controller
	char ch;				// Holds each individual character, includes whitespace
	string line;			// Holds a row from the file
	grid = new Cell**[25];		// 25 rows
	for (int i = 0; i < 25; i++) {
		grid[i] = new Cell*[79];	// 79 columns
	}
	// Now we initialize each Cell to the corresponding Object, based off of what we read in from file
	for (int row = 0; row < 25; row++) {
		getline(*file, line);
		stringstream ss(line);
		for (int col = 0; col < 79; col++) {
			// Read in a character
			ss >> noskipws >> ch;
			// Checks each of the valid characters and makes the required Cell
			if (ch == '|' || ch == '-' || ch == ' ' || ch == '+' || ch == '#' || ch == '.' || ch == '\\') {
				grid[row][col] = new Cell(row, col, ch);
			}
			else if (ch == '@') {
				
			}
			else if (ch == '0') {

			}
			else if (ch == '1') {

			}
			else if (ch == '2') {

			}
			else if (ch == '3') {

			}
			else if (ch == '4') {

			}
			else if (ch == '5') {

			}
			else if (ch == '6') {

			}
			else if (ch == '7') {

			}
			else if (ch == '8') {

			}
			else if (ch == '9') {

			}
			else if (ch == 'M') {

			}
			else if (ch == 'L') {

			}
			else if (ch == 'O') {

			}
			else if (ch == 'E') {

			}
			else if (ch == 'W') {

			}
			else if (ch == 'D') {

			}
			// Debugging warning.... just incase something slips
			else {
				cerr << "WARNING: NOT ALL CELLS ARE INITIALIZED (character in question:  " << ch << endl;
			}
		}
	}

	// Now we setup up the chambers once, which will be used for the rest of the floor
	makeChambers();

	// If it wasn't a predetermined map, then we generate the players/enemies in the correct order
	generatePlayer(race);
	generateStairs();
	// generate 10 potions randomly
	for (int i = 0; i < 10; i++) {
		generatePotion();
	}
	// generate 10 gold piles
	for (int i = 0; i < 10; i++) {
		generateGold();
	}
	// generate 20 enemies
	for (int i = 0; i < 20; i++) {
		generateEnemy();
	}

}

void Floor::generatePlayer(string race) {
	srand(time(NULL));		// random seed

	// The following computes a random number which determines which Chamber to spawn in,
	// then computes a random number which determines the actual location of spawning within the chamber

	int chamberSpawn = rand() % 5;		// Random number between 0 and 4 to determine which chamber to spawn in.
	int randIndex = rand() % chambers[chamberSpawn].size();		// Random Cell from the Random Chamber

	int posRow = chambers[chamberSpawn].at(randIndex).row;		// the row of the random location
	int posCol = chambers[chamberSpawn].at(randIndex).col;		// the column of the random location

	// Determine the race and generate it randomly!
	if (race == "shade") {
		// Delete whichever floor cell was previously there
		delete grid[posRow][posCol];
		// Makes the new player character at that position
		player = new Shade(posRow, posCol, chamberSpawn, this);
		grid[posRow][posCol] = player;
	}
	else if (race == "drow") {
		// Delete whichever floor cell was previously there
		delete grid[posRow][posCol];
		// Makes the new player character at that position
		player = new Drow(posRow, posCol, chamberSpawn, this);
		grid[posRow][posCol] = player;
	}
	else if (race == "vampire") {
		// Delete whichever floor cell was previously there
		delete grid[posRow][posCol];
		// Makes the new player character at that position
		player = new Vampire(posRow, posCol, chamberSpawn, this);
		grid[posRow][posCol] = player;
	}
	else if (race == "troll") {

	}
	else if (race == "goblin") {

	}
}
//Generates a random potion
void Floor::generatePotion() {
	srand(time(NULL));		// random seed
	// The following computes a random number which determines which Chamber to spawn in,
	// then computes a random number which determines the actual location of spawning within the chamber
		int posRow, posCol;
		while (true) {
			int chamberSpawn = rand() % 5;		// Random number between 0 and 4 to determine which chamber to spawn in.
			int randIndex; 						// Random Cell from the Random Chamber

			randIndex = rand() % chambers[chamberSpawn].size();
			posRow = chambers[chamberSpawn].at(randIndex).row;		// the row of the random location
			posCol = chambers[chamberSpawn].at(randIndex).col;		// the column of the random location
			if (grid[posRow][posCol]->getSymbol() == '.')
				break;
		}

		// Delete whichever floor cell was previously there
		delete grid[posRow][posCol];
		// Makes the new potion at that position
		grid[posRow][posCol] = new Potion(posRow, posCol, (rand() % 6));
		
}

// Generates the stairs in a chamber without the Player
void Floor::generateStairs() {
	// Gets the player's chamber location
	int playerChamber = chamberPos(player->getLocation());
	if (playerChamber == -1) {
		cerr << "Can't find player. Not spawning stairs..." << endl;
		return;
	}

	int posRow;
	int posCol;
	// Randomly selects a chamber until it finds one without the player
	while (true) {
		int chamberSpawn = rand() % 5;								// Random number between 0 and 4 to determine which chamber to spawn in.
		int randIndex = rand() % chambers[chamberSpawn].size();		// Random Cell from the Random Chamber
		// If we chose the player's chamber. we try again
		if (chamberSpawn == playerChamber) {
			continue;
		}
		else {
			posRow = chambers[chamberSpawn].at(randIndex).row;		// the row of the random location
			posCol = chambers[chamberSpawn].at(randIndex).col;		// the column of the random location
			if (grid[posRow][posCol]->getSymbol() == '.')			// ensures we don't overwrite another type
				break;	// otherwise we have found a suitable chamber
		}
	}

	// Delete whichever floor cell was previously there
	delete grid[posRow][posCol];
	// Makes the new potion at that position
	grid[posRow][posCol] = new Cell(posRow, posCol, '\\');

}

// Generates a random gold size
void Floor::generateGold() {
	srand(time(NULL));		// random seed

	// The following will randomly select a chamber and valid position for the gold to spawn,
	// then randomly select the size of the Gold pile (according to the chances described in cc3k.pdf)
	int posRow, posCol;
	while (true) {
		int chamberSpawn = rand() % 5;		// Random number between 0 and 4 to determine which chamber to spawn in.
		int randIndex; 						// Random Cell from the Random Chamber

		randIndex = rand() % chambers[chamberSpawn].size();
		posRow = chambers[chamberSpawn].at(randIndex).row;		// the row of the random location
		posCol = chambers[chamberSpawn].at(randIndex).col;		// the column of the random location
		if (grid[posRow][posCol]->getSymbol() == '.')			// ensures we don't overwrite another type
			break;
	}

	// Now that it has found a correct location, we determine the type of Gold and then spawn it
	int size = 0;							// size of gold
	int type = rand() % 8;					// random number between 0 and 7 for Gold odds
	if (type >= 0 && type < 5) {			// 5 in 8 chances for normal
		size = 2;
	}
	else if (type >= 5 && type < 7) {		// 2 in 8 chances for small
		size = 1;
	}
	else {									// 1 in 8 chances for dragon hoard
		size = 6;
		// Spawns a dragon at the gold Hoard position
		//spawnDragon(posRow, posCol, this, 'D');
	}

	// Delete whichever floor cell was previously there
	delete grid[posRow][posCol];
	// Makes the new potion at that position
	grid[posRow][posCol] = new Gold(posRow, posCol, size);
}

void Floor::generateEnemy() {
	srand(time(NULL));		// random seed

							// The following will randomly select a chamber and valid position for the gold to spawn,
							// then randomly select the size of the Gold pile (according to the chances described in cc3k.pdf)
	int posRow, posCol;
	while (true) {
		int chamberSpawn = rand() % 5;		// Random number between 0 and 4 to determine which chamber to spawn in.
		int randIndex; 						// Random Cell from the Random Chamber

		randIndex = rand() % chambers[chamberSpawn].size();
		posRow = chambers[chamberSpawn].at(randIndex).row;		// the row of the random location
		posCol = chambers[chamberSpawn].at(randIndex).col;		// the column of the random location
		if (grid[posRow][posCol]->getSymbol() == '.')			// ensures we don't overwrite another type
			break;
	}
	// Delete whichever floor cell was previously there
	delete grid[posRow][posCol];
	// Now that it has found a correct location, we determine the type of Enemy and then spawn it
	int type = rand() % 18;					// random number between 0 and 17 for Enemy type odds
	if (type >= 0 && type < 4) {			// 2 in 9 chances for Human
		grid[posRow][posCol] = new Human(posRow, posCol, this);
	}
	else if (type >= 4 && type < 7) {		// 3 in 18 chances for Dwarf
		grid[posRow][posCol] = new Human(posRow, posCol, this);
	}
	else if (type >= 7 && type < 12) {		// 5 in 18 chances for Halfling
		grid[posRow][posCol] = new Human(posRow, posCol, this);
	}
	else if (type >= 12 && type < 14) {		// 1 in 9 chances for Elf
		grid[posRow][posCol] = new Human(posRow, posCol, this);
	}
	else if (type >= 14 && type < 16) {		// 1 in 9 chances for Orc
		grid[posRow][posCol] = new Human(posRow, posCol, this);
	}
	else {									// 1 in 9 chances for Merchant
		grid[posRow][posCol] = new Human(posRow, posCol, this);
	}
}

void Floor::clearFloor() {

}

// Given a position, returns which chamber it is in.
int Floor::chamberPos(Pos pos) {
	int x = pos.row;
	int y = pos.col;

	// Loops through each of the 5 chambers
	for (int i = 0; i < 5; i++) {
		// Loops through each position in this chamber
		for (vector<Pos>::iterator it = chambers[i].begin(); it != chambers[i].end(); it++) {
			Pos hold = *it;
			// If the position matches, return the Chamber index
			if (hold.row == x && hold.col == y) {
				return i;
			}
		}
	}
	// if the position was not found, returns -1
	return -1;
}

// Handles player movement
void Floor::playerMove(string location) {
	// simply calls the virtual movement() method for the player
	bool moved = player->movement(location);
	// If the move was successful, we move the enemies and print the floor
	if (moved) {
		// makes the enemy's turn
		updateEnemies();
		player->interactVicinity();
	}
	else actionQueue += " You can't move there.";
	print();
}

void Floor::playerAttack(string direction) {
	// Attempts to attack a location
	bool attack = player->attemptStrike(direction);
	// If successful then it does the enemies turn
	if (attack) {
		// makes the enemy's turn
		updateEnemies();
		player->interactVicinity();
	}
	else actionQueue += " You can't attack that.";
	print();

}

void Floor::playerUse(string direction) {
	bool potion = player->consumePotion(direction);
	// If you successfully use a potion, computes enemies turns
	if (potion) {
		// makes the enemy's turn
		updateEnemies();
		player->interactVicinity();
	}
	else actionQueue += " That's no potion...";
	print();
}

void Floor::updateEnemies() {
	// goes through the Cell grid and prints out the symbol
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			grid[i][j]->movement();	
		}
	}
	// Goes through the Cell grid and resets all Enemy flags
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			// attempts to cast a Cell to an Enemy, if successful, then we reset its flag
			Enemy * hold = dynamic_cast<Enemy*>(grid[i][j]);
			if (hold) {
				hold->resetMove();
			}
		}
	}
}

void Floor::print() {
	// goes through the Cell grid and prints out the symbol
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			cout << grid[i][j]->getSymbol();		// outputs the symbol associated to each cell
		}
		cout << endl;	// newline (end of row)
	}
	// Outputs the 5 lines of Character info
	player->printStats();
}
