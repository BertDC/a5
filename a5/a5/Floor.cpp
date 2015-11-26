#include "Floor.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


Floor::Floor(int level) : level(level) {

}


Floor::~Floor() {

}

void Floor::loadFile(istream & input) {
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
