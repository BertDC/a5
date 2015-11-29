#include "cell.h"



cell::cell(int x, int y, char sym)
{
	posX = x;
	posY = y;
	symbol = sym;
	moves = false;
}

cell::cell(int x, int y, char sym, bool move)
{
	posX = x;
	posY = y;
	symbol = sym;
	moves = true;
}


cell::~cell()
{
}
