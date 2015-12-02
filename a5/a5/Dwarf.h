#ifndef DWARF_H
#define DWARF_H
#include "Enemy.h"

#pragma once
class Dwarf : public Enemy
{
public:
	Dwarf(int, int, Floor*);
	~Dwarf();
};

#endif

