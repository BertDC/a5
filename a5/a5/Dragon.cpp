#include "Dragon.h"
using namespace std;


Dragon::Dragon(int x, int y, Floor * flr, Gold * g) : Enemy(x, y, 'D', flr) {
	maxHp = 150;
	hp = 150;
	atk = 20;
	def = 20;
	name = "Dragon";
	pile = g;
}

// Instead of moving, a Dragon will only attack from its 2-block radius
void Dragon::movement() {

}

// Overriden death method... Allows for Player to pick up the dragon hoard
void Dragon::death() {
	pile->dragon = NULL;		// The dragon is no longer associated with the gold pile
	Enemy::death();				// Calls the normal death method
}

Dragon::~Dragon() {

}
