#include "cell.h"

#pragma once
class Item : public Cell
{
public:
	Item(int, int, char);
	~Item();
	virtual int getType() = 0;  //Used for determining type of gold/potion collected
};
