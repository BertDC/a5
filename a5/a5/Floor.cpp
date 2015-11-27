#include "Floor.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// The only constructor
Floor::Floor(int level) : level(level), grid(NULL), player(NULL), alive(true) { }


Floor::~Floor() {

}

void Floor::initialize(string filename, Controller *c) {
	controller = c;		// Allows this Floor to access the Controller
	string line;		// Holds a line, skipping leading whitespace
	char c;				// Holds each individual character, includes whitespace
	int row = 0, col = 0;
	while (getline(input, line)) {
		istringstream iss(line);
		while ((iss >> noskipws) >> c) {
			
		}
	}
}

void Floor::print() {
	// goes through the Cell grid and prints out the symbol
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			cout << grid[i][j].getSymbol();		// outputs the
		}
		cout << endl;	// newline (end of row)
	}
	// Outputs the 5 lines of Character info
	player->printStats();
}
