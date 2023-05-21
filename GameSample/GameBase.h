#pragma once
class GameBase
{
public:
	virtual void initGame() = 0;
	virtual void runGame() = 0;
	virtual void pauseGame() = 0;
	virtual void resumeGame() = 0;
	virtual void finishGame() = 0;
	virtual ~GameBase() {}
};

