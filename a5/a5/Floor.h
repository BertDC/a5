#ifndef FLOOR_H
#define FLOOR_H
#include "player.h"
#include "cell.h"
#include "Controller.h"
#include <istream>

class Cell;
class Floor {
	Cell ***grid;				// 2d-array containing each individual cell* in the map layout
	Player *player;				// pointer to the Player abstract class
	Controller *controller;		// Pointer so the Floor can interact with the Controller
	int level;					// tracks the level of the this floor
	bool alive;					// Always keeps track of the player's life to determine if dead

	
public:
	Floor(int);
	~Floor();

	void initialize(std::string, Controller *, std::fstream *);
	void makeMove(std::string);
	void generatePlayer(std::string race);
	void generatePotion();
	void generateStairs();
	void generateGold();
	void generateEnemy();
	void clearFloor();
	void print();								// prints out the floor layout
	void isAlive();								// returns the isAlive 
	bool checkLife();							// Check's the player's life total
};

#endif


