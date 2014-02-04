/*
 * Game_onEvent.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"

void Game::onEvent(SDL_Event* event) {

	keystates_ = SDL_GetKeyboardState(0);

	if (event->type == SDL_QUIT)
		isRunning_ = false;


	if(keystates_ != 0) {
		if (keystates_[SDL_SCANCODE_RIGHT] == 1)
			camera_->setPosition(camera_->getPosition()->x+0.1f, camera_->getPosition()->y);

		if (keystates_[SDL_SCANCODE_LEFT] == 1)
			camera_->setPosition(camera_->getPosition()->x-0.1f, camera_->getPosition()->y);

		if (keystates_[SDL_SCANCODE_UP] == 1)
			camera_->setPosition(camera_->getPosition()->x, camera_->getPosition()->y-0.1f);

		if (keystates_[SDL_SCANCODE_DOWN] == 1)
			camera_->setPosition(camera_->getPosition()->x, camera_->getPosition()->y+0.1f);

		if (keystates_[SDL_SCANCODE_0] == 1)
			camera_->setScale(camera_->getScale() + 0.025f);

		if (keystates_[SDL_SCANCODE_1] == 1)
			camera_->setScale(camera_->getScale() - 0.025f);
	}
}
