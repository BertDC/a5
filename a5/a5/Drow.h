#ifndef DROW_H
#define DROW_H
#include "Player.h"

class Drow : public Player
{
public:
	Drow(int, int, int, Floor*);
	~Drow();
	bool consumePotion(std::string);
};

#endif

