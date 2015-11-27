#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <sstream>
#include <fstream>
#include <iostream>
#include "Floor.h"

class Controller {
	Floor *floor[5];		// The array containing 5 floor pointers
	std::fstream *file;
	int currentLevel;
public:
	Controller(std::string filename);	// Default ctor.
	~Controller();

	void play();
	void makeMove(std::string);
	void newFloor();
};

#endif

