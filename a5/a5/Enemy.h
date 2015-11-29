#include "Creature.h"

#pragma once
class Enemy : public Creature
{
protected:
	bool hostile;
	int maxHp;
public:
	Enemy(int, int, char);
	~Enemy();
};

