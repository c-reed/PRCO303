/*
 * Game_onEvent.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"

void Game::onEvent(SDL_Event* event) {


	switch (event->type)
	{
	case SDL_QUIT:
		isRunning_ = false;
		break;

	case SDL_MOUSEMOTION:
		break;

	case SDL_MOUSEBUTTONDOWN:
		break;

	case SDL_MOUSEBUTTONUP:
		break;

	default:
		break;
	}

}
