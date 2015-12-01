#ifndef ENEMY_H
#define ENEMY_H
#include "Creature.h"
#include "Floor.h"


class Floor;

class Enemy : public Creature
{
public:
	Enemy(int, int, char, Floor *);
	~Enemy();
	virtual void death();
	void movement();
	virtual void attack(Creature*);
};

#endif

