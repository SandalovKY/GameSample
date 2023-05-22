#pragma once
#include "BaseGrid.h"
#include "GameObject.h"
#include <stdexcept>
#include <iostream>

using std::min, std::max;

enum Directions { up, down, left, right };

class SnakeSegment : public GameObject
{
private:
	SnakeSegment* nextSegment;
public:
	SnakeSegment(BaseGrid& grid, COORD coords, char symbol, SnakeSegment* next=nullptr) :
		GameObject(grid, coords, symbol), nextSegment{ next } {}
	SnakeSegment* getNextSegment()
	{
		return this->nextSegment;
	}
	void setNextSegment(SnakeSegment* next)
	{
		this->nextSegment = next;
	}
};

class Snake
{
private:
	Directions dir;
	int speed;
	SnakeSegment* tail;
	SnakeSegment* head;
	BaseGrid& grid;
	char symbol;
	bool full;
public:
	Snake(COORD coords, BaseGrid& gameGrid, char symbol = '@', int speed = 1) :
		dir{ down },
		speed{ speed },
		grid{ gameGrid },
		symbol{ symbol },
		full{ false }
	{
		head = tail = new SnakeSegment(gameGrid, coords, symbol);
	}
	bool move() {
		bool ret = false;
		COORD prevCoords, currCoords;
		prevCoords = currCoords = head->getCoords();
		switch (dir)
		{
		case up:
			currCoords.Y -= 1;
			break;
		case down:
			currCoords.Y += 1;
			break;
		case left:
			currCoords.X -= 1;
			break;
		case right:
			currCoords.X += 1;
			break;
		default:
			break;
		}
		try {
			ret = checkPos(this->grid.getSymbol(currCoords));
			head->updatePosition(currCoords);
		}
		catch (std::runtime_error& err) {
			std::cout << "GAME OVER: " << err.what() << std::endl;
			exit(0);
		}
		SnakeSegment* segmentIter = this->head->getNextSegment();
		while (segmentIter != nullptr) {
			currCoords = prevCoords;
			prevCoords = segmentIter->getCoords();
			segmentIter->updatePosition(currCoords);
			segmentIter = segmentIter->getNextSegment();
		}
		if (this->full) {
			SnakeSegment* newSegment =
				new SnakeSegment(this->grid, prevCoords, this->symbol);
			tail->setNextSegment(newSegment);
			tail = newSegment;
			this->full = false;
		}
		return ret;
	}
	bool checkPos(char posSym)
	{
		if (posSym == this->symbol) {
			throw std::runtime_error("EATEN ITSELF");
		}
		else if (posSym != ' ') {
			this->full = true;
		}
		return this->full;
	}
	int getSpeed() {
		return speed;
	}
	void changeSpeed(int add=1)
	{
		int newSpeed = this->speed + add;
		speed = min(max(1, newSpeed), 10);
	}
	void changeDir(Directions newDir) {
		this->dir = newDir;
	}
	COORD getHeadCoords()
	{
		return this->head->getCoords();
	}
	~Snake()
	{
		SnakeSegment* segmentIter = head;
		while (segmentIter != nullptr) {
			segmentIter = head->getNextSegment();
			delete head;
			head = segmentIter;
		}
	}
};

