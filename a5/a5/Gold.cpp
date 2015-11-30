#include "Gold.h"

Gold::Gold(int x, int y, int s) : Item(x, y, 'G')
{
	size = s;
	//comment
}

int Gold::getType() {
	return size;
}

Gold::~Gold()
{
}