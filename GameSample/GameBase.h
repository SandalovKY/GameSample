#pragma once
class GameBase
{
public:
	virtual void runGame() = 0;
	virtual void initGame() = 0;
	virtual ~GameBase() {}
};

