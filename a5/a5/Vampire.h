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
	std::string consumePotion(std::string);
};

#endif

