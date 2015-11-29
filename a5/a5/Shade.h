#include "Player.h"

#pragma once
class Shade : public Player
{
private:
	int maxHp;
public:
	Shade(int, int, Floor*);
	~Shade();
};

