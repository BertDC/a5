#ifndef ENEMY_H
#define ENEMY_H
#include "Creature.h"

class Enemy : public Creature
{
protected:
	bool hostile;
	int maxHp;
public:
	Enemy(int, int, char);
	~Enemy();
};

#endif

