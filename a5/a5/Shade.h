#ifndef SHADE_H
#define SHADE_H
#include "Player.h"

class Shade : public Player
{
public:
	Shade(int, int, int, Floor*);
	~Shade();
};

#endif

