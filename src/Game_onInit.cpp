/*
 * Game_onInit.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"
#include "TextureManager.h"

/*
 * Initial loading stuff
 */
bool Game::onInit() {

	//Initialise SDL systems we need
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0) {
		return false;
	}

	//Create a window and renderer in one go
	if (SDL_CreateWindowAndRenderer(960, 540, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL, &sdlWindow_, &sdlRenderer_) < 0) {
		return false;
	}


	TextureManager::GetInstance()->load("assets/char9.png", "char9", sdlRenderer_);


	universe_ = new Universe(128, 128);

	Sprite* sprite = new Sprite("char9", 128, 128, 1);
	sprite->addAnimation(0,4,0,false);
	sprite->setFrame(1);

	universe_->gameObjects.push_back(new GameObject(universe_->getTileset()[130], sprite));

	camera_ = new Camera();
	camera_->init(960, 540);

	keystates_ = SDL_GetKeyboardState(0);


	//All went well
	return true;
}


