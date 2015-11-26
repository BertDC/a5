#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include "Floor.h"

class Controller {
	Floor *floor;

public:
	Controller();
	~Controller();
	void play();

	
};

#endif

