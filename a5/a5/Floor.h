#ifndef FLOOR_H
#define FLOOR_H
class Floor {
	Cell **grid;		// 2d-array containing each individual cell in the map layout
	Controller *c;		
	Player *p;			// pointer to the Player abstract class
public:
	Floor();
	~Floor();
};

#endif


