#ifndef ORC_H
#define ORC_H
#include "Enemy.h"

class Orc : public Enemy
{
public:
	Orc(int, int, Floor*);
	void attack(Creature*);
	~Orc();
};

#endif

