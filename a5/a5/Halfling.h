#ifndef HALFLING_H
#define HALFLING_H
#include "Enemy.h"

#pragma once
class Halfling : public Enemy
{
public:
	Halfling(int, int, Floor*);
	~Halfling();
};

#endif

