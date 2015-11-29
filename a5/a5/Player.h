#ifndef PLAYER_H
#define PLAYER_H
#include "Floor.h"
#include "Creature.h"

class Floor;
class Player : public Creature
{
protected:
	int atkMod;			//Potion caused buff/debuff to attack for current floor
	int defMod;			//Potion caused buff/debuff to defense for current floor
	int chamber;		//The current chamber the Player is in
	bool knownPots[6];	//Potions discovered by the player character
	Floor *floor;		//Pointer to the current active floor object


public:
	Player(int, int, int, Floor*);
	~Player();
	virtual int getDefense();
	virtual void attack(Creature *);
	virtual void movement() = 0;
};

#endif

