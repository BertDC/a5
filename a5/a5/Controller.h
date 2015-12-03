#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <sstream>
#include <fstream>
#include <iostream>
#include "Floor.h"

class Floor;

class Controller {
	Floor *floor[5];		// The array containing 5 floor pointers
	std::fstream *file;
	int currentLevel;
	void printCharOptions();
	std::string fileName;	// stores it for resets
public:
	Controller(std::string filename);	// Default ctor.
	~Controller();
	Player * getActivePlayer();			// well, it returns the active player
	std::string getFile();				// gets the file name
	void play();
	
};

#endif

