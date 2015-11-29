#pragma once
class Cell
{
protected:
	int posX;
	int posY;
	char symbol;
	bool moves;

public:
	Cell(int, int, char);
	Cell(int, int, char, bool);
	~Cell();
};

