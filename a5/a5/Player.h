#ifndef PLAYER_H
#define PLAYER_H
#include "Creature.h"
#include "Floor.h"
#include "Potion.h"
#include <string>

class Floor;
class Player : public Creature {
protected:
	double atkMod;			//Potion caused buff/debuff to attack for current floor
	double defMod;			//Potion caused buff/debuff to defense for current floor
	int chamber;		//The current chamber the Player is in
	int gold;			//Player's current gold
	bool knownPots[6];	//Potions discovered by the player character
	char prev;			//Previous tile the character was on
	
public:
	Player(int, int, int, Floor*);
	virtual ~Player() = 0;
	int getChamber();
	virtual double getDefense();
	virtual void attack(Creature *);
	virtual bool movement(std::string);
	virtual bool consumePotion(std::string);
	virtual bool attemptStrike(std::string);
	virtual Pos getLocation();		// Gets the player location
	void printStats();		// Prints the player's stats to cout
	void interactVicinity();	//Performs interactions based on surroundings (ie take damage from enemy, spot unknown potion)
};

#endif

