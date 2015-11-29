#include "Floor.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

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

// Sets up the floor
void Floor::initialize(string race, Controller *c, fstream *file) {
	controller = c;		// Allows this Floor to access the Controller
	char ch;				// Holds each individual character, includes whitespace
	grid = new Cell**[25];		// 25 rows
	for (int i = 0; i < 25; i++) {
		grid[i] = new Cell*[79];	// 79 columns
	}
	// Now we initialize each Cell to the corresponding Object, based off of what we read in from file
	for (int row = 0; row < 25; row++) {
		for (int col = 0; col < 79; col++) {
			// Read in a character
			*file >> noskipws >> ch;
			// Checks each of the valid characters and makes the required Cell
			if (ch == '|') {

			}
			else if (ch == '-') {

			}
			else if (ch == ' ') {

			}
			else if (ch == '+') {

			}
			else if (ch == '#') {

			}
			else if (ch == '\\') {

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
		}
	}

	// If it wasn't a predetermined map, then we generate the players/enemies in the correct order
	generatePlayer(race);
	generateStairs();


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
