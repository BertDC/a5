#include "Item.h"

#pragma once
class Gold : public Item
{
protected:
	int size;
public:
	Gold(int, int, int);
	~Gold();
};