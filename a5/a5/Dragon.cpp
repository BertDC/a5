#include "Dragon.h"
using namespace std;


Dragon::Dragon(int x, int y, Floor * flr) : Enemy(x, y, 'D', flr) {
	maxHp = 150;
	hp = 150;
	atk = 20;
	def = 20;
	name = "Dragon";
}

// Instead of moving, a Dragon will only attack from its 2-block radius
void Dragon::movement() {

}

Dragon::~Dragon() {

}
