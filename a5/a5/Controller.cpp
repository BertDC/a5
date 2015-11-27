#include "Controller.h"
#include <ctime>

using namespace std;


// The default controller ctor. Enables reading in from a file
Controller::Controller(string filename) : currentLevel(0) {
	file = new fstream(filename.c_str());
}


Controller::~Controller() {

}

// Calls the Floor's move method with a given 
void Controller::makeMove(string loc) {

}

// Starts the game
void Controller::play() {
	string cmd;
	bool hasSelected = false;
	// Race select screen
	cout << "Welcome to ChamberCrawler3000!" << endl;
	cout << "Please select a valid race, or enter q to quit:" << endl;
	cout << ">  (s)hade:   125 HP, 25 ATK, 25 DEF - 50% increased score" << endl;
	cout << ">  (d)row:    150 HP, 25 ATK, 15 DEF - 1.5x amplification to potions" << endl;
	cout << ">  (v)ampire:  50 HP, 25 ATK, 25 DEF - No max HP. Gains 5 HP upon successful attack" << endl;
	cout << ">  (t)roll:   120 HP, 25 ATK, 15 DEF - Heals for 5 HP every turn" << endl;
	cout << ">  (g)oblin:  110 HP, 15 ATK, 20 DEF - Steals 5 gold from each enemy slain" << endl;

	// Command interpreter loop
	while (cin >> cmd) {
		// Race selection
		if (!hasSelected) {
			if (cmd == "q") {
				break;
			}
			// If a race is selected, begin the floor 
			else if (cmd == "s") {

			}
			else if (cmd == "d") {

			}
			else if (cmd == "v") {

			}
			else if (cmd == "t") {

			}
			else if (cmd == "g") {

			}
		}
		// The normal commands that can be issued when the game has started
		// Movement
		else if (cmd == "no") {

		}
		else if (cmd == "so") {

		}
		else if (cmd == "ea") {

		}
		else if (cmd == "we") {

		}
		else if (cmd == "ne") {

		}
		else if (cmd == "nw") {

		}
		else if (cmd == "se") {

		}
		else if (cmd == "sw") {

		}
		// potion
		else if (cmd == "u") {

		}
		// attack
		else if (cmd == "a") {

		}
		// reset
		else if (cmd == "r") {

		}
		// quit
		else if (cmd == "q") {
			break;
		}
	}
}
