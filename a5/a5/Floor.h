#ifndef FLOOR_H
#define FLOOR_H
#include "player.h"
#include "cell.h"
#include <istream>

class Floor {
	int level;			// tracks the level of the current floor
	Cell **grid;		// 2d-array containing each individual cell in the map layout
	Player *player;			// pointer to the Player abstract class
public:
	Floor(int);
	~Floor();

	void loadFile(std::istream &);
	void generatePotion();
	void generateGold();
	void generateEnemy();
	void clearFloor();
	void print();								// prints out the floor layout

};

#endif


