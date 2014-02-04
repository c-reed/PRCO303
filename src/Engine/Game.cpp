/*
 * Game.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"

Game::Game() :	isRunning_(true), sdlWindow_(0), sdlRenderer_(0), universe_(0),
				camera_(0), keystates_(0), textureManager_(0), textManager_(0)
{
	gameTime_.current = 0;
	gameTime_.last = 0;
	gameTime_.deltaT = 0;
	gameTime_.lastDeltaT = 0;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

int Game::onExecute() {
	if (!onInit()) {
		std::cout << "**Something went wrong on initialisation" << std::endl;;
		return false;
	}

	SDL_Event event;

	while (isRunning_) {
		while(SDL_PollEvent(&event)) {
			onEvent(&event);
		}
		onUpdate();
		onRender();
	}

	onCleanup();
	return 0;
}

int main() {

	Game game;

	return game.onExecute();
}
