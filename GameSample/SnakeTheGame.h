#pragma once
#include "SnakeView.h"
#include "Snake.h"
#include "Controls.h"
#include "GameBase.h"
#include "Fruits.h"

const int WIDTH = 25, HEIGHT = 25;


class SnakeTheGame : public GameBase
{
	SnakeView view;
	Snake snk;
	SnakeControls controls; 
public:
	SnakeTheGame() :
		view(WIDTH, HEIGHT),
		snk( WIDTH / 2, HEIGHT / 2, view.getViewGrid(), '*', 1 ),
		controls(snk)
	{}

	bool snakeOnFruit(Snake& snk, Fruits& fruit) {
		return snk.getCoords() == fruit.getCoords();
	}

	void runGame() override {
		view.printMessage();
		Fruits fruit{ COORD{}, 0, view.getViewGrid() };
		updateFruit(fruit, view.getViewGrid());
		while (true) {
			view.drawLines();
			controls.checkInput();
			snk.move();
			/*if (fruit.isEaten()) {
				generateOtherFruit
			}*/
		}
		/*while (true) {
			view.drawLines();
			controls.checkInput();
			snk.move();
		}*/
	}

	void initGame() override {
		std::cout << "Game initialized\n";
	}
};

