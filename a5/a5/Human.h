#include "Enemy.h"
#include "Gold.h"
#include "Floor.h"

class Human : public Enemy
{
protected:
	bool hostile;
	Gold *drop;
public:
	Human(int, int, Floor*);
	~Human();
	void death();		// Custom death method to spawn 2 gold piles
	void makeGold(int, int, Floor*);
};

