#ifndef CREATURE_H
#define CREATURE_H
#include "cell.h"
#include <iostream>

class Floor;

class Creature : public Cell
{
protected:
	double hp;			//Current health of a creature
	double maxHp;		//Maximum possible health of a creature
	double atk;		//Base attack stat of a creature
	double def;		//Base defense stat of a creature
	std::string name;
	
	Floor *floor;	//Pointer to the current active floor object

public:
	
	Creature(int, int, char, Floor *);
	virtual ~Creature() = 0;
	virtual void loseHp(double);		//Subtracts battle damage from current health value and determines if death occurs
	virtual void death() = 0;			//Called upon taking fatal damage
	virtual double getDefense();		//Returns def Integer
	virtual double getHp();				// returns current hp
	virtual std::string getName();	// returns name
};

#endif

