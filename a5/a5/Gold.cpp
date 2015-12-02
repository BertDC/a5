#include "Gold.h"
#include <iostream>

Gold::Gold(int x, int y, int s) : Item(x, y, 'G')
{
	size = s;
	dragon = NULL;
}

int Gold::getType() {
	return size;
}

Gold::~Gold()
{
}