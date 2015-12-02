#ifndef ELF_H
#define ELF_H
#include "Enemy.h"

#pragma once
class Elf : public Enemy
{
public:
	Elf(int, int, Floor*);
	void attack(Creature*);
	~Elf();
};

#endif

