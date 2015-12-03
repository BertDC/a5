#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"
#include "Gold.h"
#include "Floor.h"


class Dragon : public Enemy {
public:
	Gold * pile;
	Dragon(int, int, Floor *, Gold *);
	~Dragon();
	void movement();		// Has its own 'movement' method.
	void death();
	void checkGoldPile(int, int);	// checks if the player is within gold pile range
};


#endif


