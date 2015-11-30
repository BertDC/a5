#ifndef CREATURE_H
#define CREATURE_H
#include "cell.h"

class Floor;

class Creature : public Cell
{
protected:
	int hp;			//Current health of a creature
	int maxHp;		//Maximum possible health of a creature
	int atk;		//Base attack stat of a creature
	int def;		//Base defense sta of a creature
	Floor *floor;	//Pointer to the current active floor object

public:
	Creature(int, int, char, Floor *);
	virtual ~Creature() = 0;
	//virtual void movement();		//Default method randomly moves the creature by one square
	virtual void attack(Creature*);
	virtual void loseHp(int);		//Subtracts battle damage from current health value and determines if death occurs
	virtual void death();			//Called upon taking fatal damage
	virtual int getDefense();		//Returns def Integer
};

#endif

