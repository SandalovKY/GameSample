#include "SnakeView.h"
#include "Snake.h"
#include "Controls.h"
#include "GameBase.h"
#include <Windows.h>

#include "SnakeTheGame.h"

#include <iostream>

class EngineContext;
class EngineState;
class OnStart;
class OnPlay;

class EngineState {
protected:
	EngineContext* context;
public:
	void setContext(EngineContext* context) {
		this->context = context;
	}
	virtual void handleGame(GameBase* game) = 0;
};

class EngineContext {
	GameBase *game;
	EngineState* state;
public:
	EngineContext(EngineState* initialState, GameBase* game) :
		state(initialState),
		game(game) {}
	void changeState(EngineState* other_state) {
		delete state;
		state = other_state;
	}
	void handleGame() {
		this->state->handleGame(this->game);
	}
	~EngineContext() {
		delete this->state;
		delete this->game;
	}
};

class OnMenu : public EngineState {

};

class OnPlay : public EngineState {
	void handleGame(GameBase* game) {
		std::cout << "On game run\n";
		game->runGame();
	}
};

class OnStart : public EngineState {
	void handleGame(GameBase* game) {
		std::cout << "On game init\n";
		game->initGame();
		EngineState* new_state = new OnPlay{};
		new_state->setContext(context);
		context->changeState(new_state);
	}
};

class OnPause : public EngineState {

};

class OnFinish : public EngineState {

};

int main() {
	/*EngineState* initState = new OnStart();
	GameBase* game = new SnakeTheGame();
	EngineContext context(initState, game);
	initState->setContext(&context);
	context.handleGame();*/

	SnakeTheGame game{};
	game.runGame();

	return 0;
}