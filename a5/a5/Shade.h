#ifndef SHADE_H
#define SHADE_H
#include "Player.h"

class Shade : public Player
{
private:
	int maxHp;
public:
	Shade(int, int, int, Floor*);
	~Shade();
	void movement(std::string);
};

#endif

