#pragma once
#include "BaseGrid.h"
#include "GameObject.h"
#include <Windows.h>

class Fruits: public GameObject
{
private:
public:
	Fruits(COORD crd, char symbol, BaseGrid& grid) : GameObject(grid, crd, symbol) {}
};

