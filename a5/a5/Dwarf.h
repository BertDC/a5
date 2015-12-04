#ifndef DWARF_H
#define DWARF_H
#include "Enemy.h"

class Dwarf : public Enemy
{
public:
	Dwarf(int, int, Floor*);
	~Dwarf();
};

#endif

