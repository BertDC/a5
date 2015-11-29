#include "Floor.h"
#include "Shade.h"
#include "cell.h"
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
Floor::Floor(int level) : level(level), grid(NULL), player(NULL), alive(true) { }

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
				cerr << "adding " << ch << " character." << endl;
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
	cerr << "chambers successfully initialized" << endl;

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
		grid[posRow][posCol] = new Shade(posRow, posCol, chamberSpawn, this);
	}
	else if (race == "drow") {

	}
	else if (race == "vampire") {

	}
	else if (race == "troll") {

	}
	else if (race == "goblin") {

	}
}

void Floor::generatePotion() {

}

void Floor::generateStairs() {

}

void Floor::generateGold() {

}

void Floor::generateEnemy() {

}

void Floor::clearFloor() {

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
	//player->printStats();
}
