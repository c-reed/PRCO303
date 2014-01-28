/*
 * Game_gameTime.cpp
 *
 *  Created on: 28 Jan 2014
 *      Author: creed
 */

#include "Game.h"

void Game::updateGameTime() {

	gameTime_.last = gameTime_.current;
	gameTime_.current = SDL_GetTicks();
	gameTime_.deltaT = (float)(gameTime_.current - gameTime_.last) / 1000.0f;
}

Uint32 Game::getGameTime() {
	return gameTime_.current;
}

float Game::getDeltaT() {
	return gameTime_.deltaT;
}

int Game::getFrameRate() {

	int framerate = 0;

	framerate = (int)(1.0f / gameTime_.deltaT);

	return framerate;
}

