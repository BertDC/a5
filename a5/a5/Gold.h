#ifndef GOLD_H
#define GOLD_H
#include "Item.h"

class Dragon;

class Gold : public Item
{
protected:
	int size;
	
public:
	Dragon * dragon;		// The dragon that's associated to this Gold pile
	Gold(int, int, int);	// (posx, posy, goldSize)
	~Gold();
	int getType();
};

#endif