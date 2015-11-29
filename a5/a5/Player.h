#include "floor.h"
#include "Creature.h"

#pragma once
class Player : public Creature
{
protected:
	int atkMod;			//Potion caused buff/debuff to attack for current floor
	int defMod;			//Potion caused buff/debuff to defense for current floor
	bool knownPots[6];	//Potions discovered by the player character
	Floor *floor;		//Pointer to the current active floor object


public:
	Player(int, int, Floor*);
	~Player();
	virtual int getDefense();
	virtual void attack(Creature *);
	virtual void movement() = 0;
};

