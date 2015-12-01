#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Player.h"

#pragma once
class Vampire : public Player
{
public:
	Vampire(int, int, int, Floor*);
	~Vampire();
	void attack(Creature *);
	bool consumePotion(std::string);
};

#endif

