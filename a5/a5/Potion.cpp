#include "Potion.h"



Potion::Potion(int x, int y, int t) : Item(x, y, 'P')
{
	type = t;
}

int Potion::getType() {
	return type;
}

Potion::~Potion()
{
}