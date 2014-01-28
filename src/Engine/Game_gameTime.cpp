/*
 * Game_gameTime.cpp
 *
 *  Created on: 28 Jan 2014
 *      Author: creed
 */

#include "Game.h"

void Game::updateGameTime() {

	lastGameTime_ = gameTime_;
	gameTime_ = SDL_GetTicks();

	deltaT_ = gameTime_ - lastGameTime_;
}

Uint32 Game::getGameTime() {
	return gameTime_;
}

Uint32 Game::getDeltaT() {
	return deltaT_;
}


