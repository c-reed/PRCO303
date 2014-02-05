/*
 * Game_onEvent.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"

void Game::onEvent(SDL_Event* event) {


	static Vector2D* mousePos = new Vector2D(0,0);

	switch (event->type)
	{
	case SDL_QUIT:
		isRunning_ = false;
		break;

	case SDL_MOUSEBUTTONDOWN:
		mousePos->x = event->motion.x;
		mousePos->y = event->motion.y;
		std::cout << "MOUSE X: " << mousePos->x << std::endl;
		std::cout << "MOUSE Y: " << mousePos->y << std::endl;
		break;

	case SDL_MOUSEBUTTONUP:
		break;

	default:
		break;
	}


}
