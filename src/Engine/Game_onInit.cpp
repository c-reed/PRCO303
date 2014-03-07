/*
 * Game_onInit.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "../Agent.h"
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
		std::cout << "**Something went terribly wrong.\n" << SDL_GetError() << std::endl;
		return false;
	}

	//Initialise spriteManager and load textures
	textureManager_ = new TextureManager();
	if (!textureManager_->load("assets/placeholder_person.png", "placeholder_person", sdlRenderer_)) {
		return false;
	}
	if (!textureManager_->load("assets/tileSheet.png", "tile", sdlRenderer_)) {
		return false;
	}

	//Set up text rendering system
	textManager_ = new TextManager();
	textManager_->init();

	//create the universe the game takes place in
	universe_ = new Universe(128, 128);


	Sprite* sprite = new Sprite("placeholder_person", 32, 32, 1);
	sprite->addAnimation(0,1,0,false);
	sprite->setFrame(1);

	//TODO REMOVE temporary for testing
	Agent* a = new Agent(universe_->getTileset()[130], sprite);
	universe_->gameObjects.push_back(a);
	a = new Agent(universe_->getTileset()[134], sprite);
	universe_->gameObjects.push_back(a);

	for (int i = 0; i < 48; i++) {
		a = new Agent(universe_->getTileset()[rand() % (128 * 128)], sprite);
		universe_->gameObjects.push_back(a);
	}

	universe_->getTileset()[135]->setStatus(TILE_STATUS_BLOCKED);
	universe_->getTileset()[135 - 128]->setStatus(TILE_STATUS_BLOCKED);
	universe_->getTileset()[135 + 128]->setStatus(TILE_STATUS_BLOCKED);

	camera_ = new Camera(960, 540);
	camera_->setPosition(25.0f, 25.0f);

	//All went well
	return true;
}
