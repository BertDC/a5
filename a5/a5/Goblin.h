#ifndef GOBLIN_H
#define GOBLIN_H
#include "Player.h"

#pragma once
class Goblin : public Player
{
public:
	Goblin(int, int, int, Floor*);
	~Goblin();
};

#endif

