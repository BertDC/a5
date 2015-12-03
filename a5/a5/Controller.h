#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <sstream>
#include <fstream>
#include <iostream>
#include "Floor.h"

class Floor;

class Controller {
	Floor *floor;			// The pointer to the floor pointers
	std::fstream *file;
	void printCharOptions();
	std::string fileName;	// stores it for resets
public:
	Controller(std::string filename);	// Default ctor.
	~Controller();
	std::string getFile();				// gets the file name
	void play();
	
};

#endif

