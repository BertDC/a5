#ifndef DROW_H
#define DROW_H
#include "Player.h"

#pragma once
class Drow : public Player
{
public:
	Drow(int, int, int, Floor*);
	~Drow();
	std::string consumePotion(std::string);
};

#endif

