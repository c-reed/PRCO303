/*
 * Game_onCleanup.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"

void Game::onCleanup() {
	//Dispose of everything properly so we can get out of here
	SDL_DestroyWindow(sdlWindow_);
	SDL_DestroyRenderer(sdlRenderer_);
	SDL_Quit();
}
