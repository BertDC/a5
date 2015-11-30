#ifndef PLAYER_H
#define PLAYER_H
#include "Creature.h"
#include "Floor.h"
#include <string>

class Floor;
class Player : public Creature {
protected:
	int atkMod;			//Potion caused buff/debuff to attack for current floor
	int defMod;			//Potion caused buff/debuff to defense for current floor
	int chamber;		//The current chamber the Player is in
	bool knownPots[6];	//Potions discovered by the player character
	char prev;			//Previous tile the character was on
	
public:
	Player(int, int, int, Floor*);
	virtual ~Player() = 0;
	int getChamber();
	virtual int getDefense();
	virtual void attack(Creature *);
	virtual bool movement(std::string);
};

#endif

