#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <stdexcept>

class BaseGrid {
protected:
	std::vector<std::string> grid;
public:
	BaseGrid(int h, int w) : grid(h, std::string(w, ' ')) {}
	const std::string& getLine(int num) const
	{
		return this->grid[num];
	}
	void setSymbol(COORD crd, char symbol)
	{
		checkCoords(crd);
		grid[crd.Y][crd.X] = symbol;
	}
	char getSymbol(COORD crd) const
	{
		checkCoords(crd);
		return grid[crd.Y][crd.X];
	}
	void clear()
	{
		for (int i = 0; i < grid.size(); ++i) {
			grid[i] = std::string(grid[i].size(), ' ');
		}
	}
	void clear(COORD crd)
	{
		checkCoords(crd);
		grid[crd.Y][crd.X] = ' ';
	}
	int getHeight() const { return this->grid.size(); }
	int getWidth() const { return this->grid[0].size(); }
private:
	void checkCoords(COORD crd) const
	{
		if (crd.Y >= grid.size() || crd.X >= grid[0].size() ||
			crd.Y < 0 || crd.X < 0) {
			throw std::runtime_error("OUT OF BOUNDS");
		}
	}
};

