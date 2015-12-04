#ifndef HALFLING_H
#define HALFLING_H
#include "Enemy.h"

class Halfling : public Enemy
{
public:
	Halfling(int, int, Floor*);
	~Halfling();
};

#endif

