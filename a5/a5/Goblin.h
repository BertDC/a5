#ifndef GOBLIN_H
#define GOBLIN_H
#include "Player.h"
#include <sstream>
#include <cstdlib>

class Goblin : public Player
{
public:
	Goblin(int, int, int, Floor*);
	void attack(Creature*);
	~Goblin();
};

#endif

