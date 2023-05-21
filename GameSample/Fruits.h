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
//		updateFruit(*this, grid);
		grid.setSymbol(this->crd, this->symbol);
	}

	const COORD getCoords() const {
		return this->crd;
	}

//	friend void updateFruit(Fruits& fruit, BaseGrid& grid);
};

//void updateFruit(Fruits& fruit, BaseGrid& grid) {
//	fruit.crd.X = rand() % grid.getWidth();
//	fruit.crd.Y = rand() % grid.getHeight();
//	fruit.symbol = (rand() % 2 == 0) ? 42 : 43;
//}

