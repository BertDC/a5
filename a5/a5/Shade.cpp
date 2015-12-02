#include "Shade.h"
#include <sstream>
using namespace std;


Shade::Shade(int x, int y, int ch, Floor *flr) : Player(x, y, ch, flr)
{
	hp = 125;
	maxHp = 125;
	atk = 25;
	def = 25;
	name = "Shade";
	chamber = ch;
}

void Shade::displayScore() {
	stringstream ss;
	ss << endl << "Your run has ended. You achieved a score of " << gold*2 << "." << endl;;
	floor->actionQueue += ss.str();
}

Shade::~Shade() {

}

