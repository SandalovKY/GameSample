#pragma once
#include "View.h"


class SnakeView : public View
{
public:
	SnakeView(int w, int h) : View(w, h) {}
	~SnakeView() {}
	void printMessage() const override {
		std::cout << "Snake play. Use WASD to control snake." << std::endl;
	}
};

