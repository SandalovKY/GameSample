#pragma once
#include "Snake.h"
#include <conio.h>


class Controls {
public:
	virtual void checkInput() = 0;
};

class SnakeControls : public Controls {
	Snake& snk;
public:
	SnakeControls(Snake& snake) : snk(snake) {}
	void checkInput() override {
		Sleep(1000 / snk.getSpeed());
		if (_kbhit()) {
			switch (_getch())
			{
			case 'w':
				snk.changeDir(up);
				break;
			case 'a':
				snk.changeDir(left);
				break;
			case 's':
				snk.changeDir(down);
				break;
			case 'd':
				snk.changeDir(right);
				break;
			default:
				break;
			}
		}
	}
};

