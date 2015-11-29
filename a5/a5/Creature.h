#include "cell.h"

#pragma once
class Creature : public cell
{
protected:
	int hp;			//Current health of a creature
	int atk;		//Base attack stat of a creature
	int def;		//Base defense sta of a creature

public:
	Creature(int, int, char);
	~Creature();
	virtual void movement();		//Default method randomly moves the creature by one square
	virtual void attack(Creature*);
	virtual void loseHp(int);		//Subtracts battle damage from current health value and determines if death occurs
	virtual void death();			//Called upon taking fatal damage
	virtual int getDefense();		//Returns def Integer
};

