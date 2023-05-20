#pragma once
#include "BaseGrid.h"

#include <string>
#include <iostream>

class View
{
protected:
	int height;
	int width;
	BaseGrid grid;
	void resetView(short start_x, short start_y) const {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { start_x, start_y });
	}
public:
	View(int w, int h) : height(h), width(w), grid(h, w) {}
	virtual ~View() {
		//system("cls");
	}
	// Вывод информационного сообщения
	virtual void printMessage() const {
		std::string controlsLine{ "Now you are using empty view." };
		std::cout << controlsLine << std::endl;
	}
	// Вывод построчно
	virtual void drawLines() const {
		resetView(0, 1);
		std::string edgeLine(static_cast<size_t>(width + 2), '#');
		std::cout << edgeLine << std::endl;
		for (int y = 0; y < height; ++y) {
			std::cout << '#' << grid.getLine(y) << '#' << std::endl;
		}
		std::cout << edgeLine << std::endl;
	}
	BaseGrid& getViewGrid() {
		return this->grid;
	}
};

