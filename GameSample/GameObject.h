#pragma once

#include "BaseGrid.h"


class GameObject
{
protected:
	BaseGrid& grid;
	COORD coords;
	char symbol;
public:
	// В момент создания объекта надо добавить его на грид
	GameObject(BaseGrid& grid, COORD coords, char symbol) :
		grid{ grid }, coords{ coords }, symbol{ symbol }
	{
		grid.setSymbol(this->coords, this->symbol);
	}
	// При изменении состояния объекта,
	// в данном случае при изменении его координат,
	// Сначала удаляем с грида символ объекта в старом состоянии
	// Затем добавляем уже обновленный объект на грид
	void updatePosition(COORD new_coords)
	{
		grid.clear(this->coords);
		this->coords = new_coords;
		grid.setSymbol(this->coords, this->symbol);
	}
	// При обновлении символа для отображения объекта можно не удалять его с грида,
	// а просто перезаписать
	void updateSymbol(char new_symbol)
	{
		this->symbol = new_symbol;
		grid.setSymbol(this->coords, this->symbol);
	}
	void updateWClean(COORD newCoords, char newSym)
	{
		this->coords = newCoords;
		this->symbol = newSym;
		grid.setSymbol(this->coords, this->symbol);
	}
	const COORD getCoords() const {
		return this->coords;
	}
	// Удаляем объект с грида в момент его уничтожения
	virtual ~GameObject()
	{
		grid.clear(this->coords);
	}
};
