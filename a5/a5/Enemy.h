#ifndef ENEMY_H
#define ENEMY_H
#include "Creature.h"
#include "Floor.h"


class Floor;

class Enemy : public Creature {
	bool hasMoved;				// used to prevent more than one move
public:
	Enemy(int, int, char, Floor *);
	~Enemy();
	virtual void death();
	void movement();
	void resetMove();
	virtual void attack(Creature*);
};

#endif

