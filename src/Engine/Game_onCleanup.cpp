/*
 * Game_onCleanup.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"

void Game::onCleanup() {

	//TODO CLEANUP
	delete universe_;
	delete camera_;
	delete textureManager_;
	delete textManager_;

	textManager_ = 0;
	textureManager_ = 0;
	camera_ = 0;
	universe_ = 0;

	//Dispose of everything properly so we can get out of here
	SDL_DestroyWindow(sdlWindow_);
	SDL_DestroyRenderer(sdlRenderer_);
	SDL_Quit();
}
