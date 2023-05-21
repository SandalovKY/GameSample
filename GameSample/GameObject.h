#pragma once

#include "BaseGrid.h"


class GameObject
{
protected:
	BaseGrid& grid;
	COORD coords;
	char symbol;
public:
	// � ������ �������� ������� ���� �������� ��� �� ����
	GameObject(BaseGrid& grid, COORD coords, char symbol) :
		grid{ grid }, coords{ coords }, symbol{ symbol }
	{
		grid.setSymbol(this->coords, this->symbol);
	}
	// ��� ��������� ��������� �������,
	// � ������ ������ ��� ��������� ��� ���������,
	// ������� ������� � ����� ������ ������� � ������ ���������
	// ����� ��������� ��� ����������� ������ �� ����
	void updatePosition(COORD new_coords)
	{
		grid.clear(this->coords);
		this->coords = new_coords;
		grid.setSymbol(this->coords, this->symbol);
	}
	// ��� ���������� ������� ��� ����������� ������� ����� �� ������� ��� � �����,
	// � ������ ������������
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
	// ������� ������ � ����� � ������ ��� �����������
	virtual ~GameObject()
	{
		grid.clear(this->coords);
	}
};
