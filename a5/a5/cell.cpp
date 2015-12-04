#include "cell.h"


// The Position class
Pos::Pos(int x, int y) : row(x), col(y) { }
Pos::~Pos() { }


Cell::Cell(int x, int y, char sym)
{
	posX = x;
	posY = y;
	symbol = sym;
	moves = false;
	inChamber = false;
	chamber = -1;
}

Cell::Cell(int x, int y, char sym, bool move)
{
	posX = x;
	posY = y;
	symbol = sym;
	moves = true;
	inChamber = false;
}

// Gets the cell's location
Pos Cell::getLocation() {
	Pos pos(posX, posY);
	return pos;
}

Cell::~Cell()
{
}

int Cell::getChamber() {
	return chamber;
}

void Cell::setChamber(int ch) {
	chamber = ch;
}

char Cell::getSymbol() {
	return symbol;
}

int Cell::getType() {
	return 0;
}

void Cell::movement() {}


