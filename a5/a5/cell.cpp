#include "cell.h"

Cell::Cell(int x, int y, char sym)
{
	posX = x;
	posY = y;
	symbol = sym;
	moves = false;
	inChamber = false;
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

char Cell::getSymbol() {
	return symbol;
}

int Cell::getType() {
	return 0;
}

void Cell::movement() {}


