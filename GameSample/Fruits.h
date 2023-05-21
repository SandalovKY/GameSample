#pragma once
#include <Windows.h>
#include "BaseGrid.h"

class Fruits
{
	char symbol;
	COORD crd;
	BaseGrid& grid;
public:
	Fruits(COORD crd, char symbol, BaseGrid& grid) :
		crd(crd),
		symbol(symbol),
		grid(grid)
	{
		grid.setSymbol(this->crd, this->symbol);
	}

	void eat() {
		grid.setSymbol(this->crd, this->symbol);
	}

	const COORD getCoords() const {
		return this->crd;
	}
};



