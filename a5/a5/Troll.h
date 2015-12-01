#ifndef TROLL_H
#define TROLL_H
#include "Player.h"

#pragma once
class Troll : public Player
{
public:
	Troll(int, int, int, Floor*);
	~Troll();
	void attack(Creature *);
	bool movement(std::string);
	bool consumePotion(std::string);
};

#endif

