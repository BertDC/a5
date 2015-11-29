#pragma once
class cell
{
protected:
	int posX;
	int posY;
	char symbol;
	bool moves;

public:
	cell(int, int, char);
	cell(int, int, char, bool);
	~cell();
};

