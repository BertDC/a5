#include "Controller.h"
#include <ctime>

using namespace std;


// The default controller ctor. Enables reading in from a file
Controller::Controller(string filename) : fileName(filename) {
	file = new fstream(fileName.c_str());
	floor = NULL;
}


Controller::~Controller() {
	delete floor;
}

string Controller::getFile() {
	return fileName;
}

// Starts the game
void Controller::play() {
	string cmd;
	bool hasSelected = false;
	// Race select screen
	printCharOptions();

	// Command interpreter loop
	while (cin >> cmd) {
		// Race selection
		if (!hasSelected) {
			if (cmd == "q") {
				break;
			}
			// If a race is selected, begin the floor 
			else if (cmd == "s") {
				string ch = "shade";
				floor = new Floor(0);
				floor->initialize(ch, this, file);
				floor->print();
				hasSelected = true;
			}
			else if (cmd == "d") {
				string ch = "drow";
				floor = new Floor(0);
				floor->initialize(ch, this, file);
				floor->print();
				hasSelected = true;
			}
			else if (cmd == "v") {
				string ch = "vampire";
				floor = new Floor(0);
				floor->initialize(ch, this, file);
				floor->print();
				hasSelected = true;
			}
			else if (cmd == "t") {
				string ch = "troll";
				floor = new Floor(0);
				floor->initialize(ch, this, file);
				floor->print();
				hasSelected = true;
			}
			else if (cmd == "g") {
				string ch = "goblin";
				floor = new Floor(0);
				floor->initialize(ch, this, file);
				floor->print();
				hasSelected = true;
			}
		}
		// reset
		else if (cmd == "r") {
			if (floor) {
				delete floor;
			}
			hasSelected = false;
			printCharOptions();
			if (file) {
				delete file;
			}
			file = new fstream(fileName.c_str());
			floor = new Floor(0);
		}
		// quit
		else if (cmd == "q") {
			break;
		}
		// The normal commands that can be issued when the game has started
		// Checks all directions
		else if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
			|| cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se") {
			if (!floor) continue;
			floor->playerMove(cmd);
		}

		// Use potion
		else if (cmd == "u") {
			cin >> cmd;
			// Checks all directions
			if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
				|| cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se") {
				if (!floor) continue;
				floor->playerUse(cmd);
			}

		}
		// Attack a location
		else if (cmd == "a") {
			cin >> cmd;
			// Checks all directions
			if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
				|| cmd == "nw" || cmd == "ne" || cmd == "sw" || cmd == "se") {
				if (!floor) continue;
				floor->playerAttack(cmd);
			}
		}
	}
}

void Controller::printCharOptions(){
	cout << "Welcome to ChamberCrawler3000!" << endl;
	cout << "Please select a valid race, or enter q to quit:" << endl;
	cout << ">  (s)hade:   125 HP, 25 ATK, 25 DEF - 50% increased score" << endl;
	cout << ">  (d)row:    150 HP, 25 ATK, 15 DEF - 1.5x amplification to potions" << endl;
	cout << ">  (v)ampire:  50 HP, 25 ATK, 25 DEF - No max HP. Gains 5 HP upon successful attack" << endl;
	cout << ">  (t)roll:   120 HP, 25 ATK, 15 DEF - Heals for 5 HP every turn" << endl;
	cout << ">  (g)oblin:  110 HP, 15 ATK, 20 DEF - Steals 5 gold from each enemy slain" << endl;
}
