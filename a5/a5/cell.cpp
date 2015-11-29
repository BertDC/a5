#include "cell.h"



Cell::Cell(int x, int y, char sym)
{
	posX = x;
	posY = y;
	symbol = sym;
	moves = false;
}

Cell::Cell(int x, int y, char sym, bool move)
{
	posX = x;
	posY = y;
	symbol = sym;
	moves = true;
}


Cell::~Cell()
{
}
