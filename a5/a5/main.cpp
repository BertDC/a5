#include "Controller.h"
using namespace std;


// The main function acts as our controller with the program. It holds the Floor object on the Stack
int main(int argc, char *argv[]) {
	string file;
	if (argc > 1) {
		// Gets the inputted file text
		file = argv[1];
	} 
	else {
		// Case where no filename is given. Uses default
		file = "map.txt";
	}

	// Checks if the given map is a predetermined save file
	fstream *f = new fstream(file.c_str());
	char ch;
	while ((*f >> noskipws) >> ch) {
		if (ch == '@') {
			Floor::predetermined = true;
			break;
		}
	}
	delete f;

	// Defaults the DLC to OFF
	Controller c(file);
	c.play();

}