/*
 * Game_onUpdate.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"

/*
 * Update logic for each frame of the game loop
 */
void Game::onUpdate() {

	updateGameTime();

	std::cout << getFrameRate() << "\t" << getDeltaT() << std::endl;


	keystates_ = SDL_GetKeyboardState(0);

	if(keystates_ != 0)
	{
		if (keystates_[SDL_SCANCODE_RIGHT] == 1)
			camera_->setPosition(camera_->getPosition()->x+5.f*gameTime_.deltaT, camera_->getPosition()->y);

		if (keystates_[SDL_SCANCODE_LEFT] == 1)
			camera_->setPosition(camera_->getPosition()->x-5.f*gameTime_.deltaT, camera_->getPosition()->y);

		if (keystates_[SDL_SCANCODE_UP] == 1)
			camera_->setPosition(camera_->getPosition()->x, camera_->getPosition()->y-5.f*gameTime_.deltaT);

		if (keystates_[SDL_SCANCODE_DOWN] == 1)
			camera_->setPosition(camera_->getPosition()->x, camera_->getPosition()->y+5.f*gameTime_.deltaT);

		if (keystates_[SDL_SCANCODE_0] == 1)
			camera_->setScale(camera_->getScale() + 0.025f);

		if (keystates_[SDL_SCANCODE_1] == 1)
			camera_->setScale(camera_->getScale() - 0.025f);

	}

}


