#ifndef DRAGON_H
#define DRAGON_H
#include "Enemy.h"
#include "Gold.h"
#include "Floor.h"


class Dragon :
	public Enemy
{
public:
	Dragon(int, int, Floor *);
	~Dragon();
	void movement();		// Has its own 'movement' method.
};


#endif


