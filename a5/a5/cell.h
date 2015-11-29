#ifndef CELL_H
#define CELL_H
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
	bool inChamber;			// Whether the Cell has already been added to a chamber or not
	char getSymbol();		// Returns the symbol associated to this cell
};

#endif

