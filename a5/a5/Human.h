#include "Enemy.h"
#include "Gold.h"
#include "Floor.h"

#pragma once
class Human : public Enemy
{
protected:
	bool hostile;
	Gold *drop;
public:
	Human(int, int, Floor*);
	~Human();
};

