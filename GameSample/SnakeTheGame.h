#pragma once
#include "SnakeView.h"
#include "Snake.h"
#include "Controls.h"
#include "GameBase.h"
#include "Fruits.h"

const int WIDTH = 15, HEIGHT = 15;

class SnakeTheGame : public GameBase
{
	SnakeView view;
	Snake snk;
	Fruits* fruit;
	SnakeControls controls;
	int points;
public:
	SnakeTheGame() :
		view(WIDTH, HEIGHT),
		snk({WIDTH / 2, HEIGHT / 2}, view.getViewGrid(), '*', 6),
		controls(snk),
		fruit(new Fruits{ {WIDTH / 4, HEIGHT / 4}, '%', view.getViewGrid() }),
		points(0)
	{}

	bool snakeOnFruit() {
		return abs(snk.getHeadCoords().X - fruit->getCoords().X) == 1 &&
			snk.getHeadCoords().Y == fruit->getCoords().Y ||
			abs(snk.getHeadCoords().Y - fruit->getCoords().Y) == 1 &&
			snk.getHeadCoords().X == fruit->getCoords().X;
	}

	void pauseGame() override {}
	void resumeGame() override {}
	void finishGame() override {}

	void runGame() override {
		view.printMessage();
		updateFruit(fruit, view.getViewGrid());
		updateFruit(fruit, view.getViewGrid());
		updateFruit(fruit, view.getViewGrid());
		while (true) {
			std::string pointsInfo("Points: ");
			pointsInfo.append(std::to_string(this->points));
			view.updateDynamicInfo(pointsInfo);
			view.drawLines();
			controls.checkInput();
			if (snk.move()) {
				generateNewFruit();
				this->points += 1;
			}
		}
	}

	void generateNewFruit() {
		COORD newCoords;
		newCoords.X = rand() % view.getViewGrid().getWidth();
		newCoords.Y = rand() % view.getViewGrid().getHeight();
		char newSymbol = '%';
		this->fruit->updateWClean(newCoords, newSymbol);
	}

	void initGame() override {
		std::cout << "Game initialized\n";
	}
};

