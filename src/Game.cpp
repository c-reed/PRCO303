/*
 * Game.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"
#include "Universe.h"

Game::Game() {

	universe_ = 0;
	sdlWindow_ = 0;
	sdlRenderer_ = 0;
	camera_ = 0;
	keystates_ = 0;
	isRunning_ = true;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

int Game::onExecute() {
	if (!onInit()) {
		return false;
	}

	SDL_Event event;

	while (isRunning_) {
		while(SDL_PollEvent(&event)) {
			onEvent(&event);
		}
		onUpdate();
		onRender();


		SDL_Delay(10);
	}

	onCleanup();
	return 0;
}

int main() {

	Game game;

	return game.onExecute();
}
