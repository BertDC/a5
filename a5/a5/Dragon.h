#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"
#include "Gold.h"
#include "Floor.h"


class Dragon : public Enemy {
	Gold * pile;
public:
	Dragon(int, int, Floor *, Gold *);
	~Dragon();
	void movement();		// Has its own 'movement' method.
	void death();
};


#endif


