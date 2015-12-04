#ifndef MERCHANT_H
#define MERCHANT_H
#include "Enemy.h"

class Merchant : public Enemy
{
public:
	Merchant(int, int, Floor*);
	void movement();
	void death();
	~Merchant();
};

#endif

