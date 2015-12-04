#ifndef ITEM_H
#define ITEM_H
#include "cell.h"

class Item : public Cell
{
public:
	Item(int, int, char);
	~Item();
	virtual int getType() = 0;  //Used for determining type of gold/potion collected
};

#endif
