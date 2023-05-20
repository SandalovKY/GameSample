#pragma once
#include "BaseGrid.h"
#include <stdexcept>
#include <iostream>

enum Directions { up, down, left, right };

class Snake
{
	BaseGrid& grid;
	COORD head;
	char snakeSymbol;
	Directions dir;
	int speed;
public:
	Snake(int x, int y, BaseGrid& gameGrid, char symbol = '@', int speed = 1) :
		grid{ gameGrid },
		snakeSymbol{ symbol },
		dir{ down },
		speed{ speed }
	{
		head.X = x;
		head.Y = y;
		grid.setSymbol(head, snakeSymbol);
	}
	void move() {
		grid.clear();
		switch (dir)
		{
		case up:
			head.Y -= 1;
			break;
		case down:
			head.Y += 1;
			break;
		case left:
			head.X -= 1;
			break;
		case right:
			head.X += 1;
			break;
		default:
			break;
		}
		try {
			grid.setSymbol(head, snakeSymbol);
		}
		catch (std::runtime_error& err) {
			std::cout << "GAME OVER\n";
			exit(0);
		}
	}
	const COORD getCoords() const {
		return this->head;
	}
	int getSpeed() {
		return speed;
	}
	void changeDir(Directions newDir) {
		this->dir = newDir;
	}
};

