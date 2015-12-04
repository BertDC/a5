#include "Item.h"
#include <string>

class Potion : public Item
{
protected:
	int type;
public:
	Potion(int, int, int);
	int getType();
	~Potion();
};