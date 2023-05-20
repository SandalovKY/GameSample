#pragma once
#include <vector>
#include <string>
#include <Windows.h>

#include <stdexcept>

// height width

class BaseGrid {
protected:
	std::vector<std::string> grid;
public:
	BaseGrid(int h, int w) : grid(h, std::string(w, ' ')) {}
	const std::string& getLine(int num) const {
		return this->grid[num];
	}
	void setSymbol(COORD crd, char symbol) {
		if (crd.Y >= grid.size() || crd.X >= grid[0].size()) {
			throw std::runtime_error("OUT OF BOUNDS");
		}
		grid[crd.Y][crd.X] = symbol;
	}
	void clear() {
		for (int i = 0; i < grid.size(); ++i) {
			grid[i] = std::string(grid[i].size(), ' ');
		}
	}
	int getHeight() { return this->grid.size(); }
	int getWidth() { return this->grid[0].size(); }
};

