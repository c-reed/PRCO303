/*
 * Game_onRender.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"
#include "TextureManager.h"
#include "Camera.h"


/*
 * Render the frame
 */
void Game::onRender() {

	SDL_SetRenderDrawColor(sdlRenderer_, 123,123,123,255);

	//clear the screen		SDL_RenderGetScale()

	SDL_RenderClear(sdlRenderer_);

	//Tile** tileset = universe->getTileset();

	GameObject* gobj = universe_->gameObjects.back();

	Vector2D pos = camera_->getDrawPos(gobj->getPos());

	TextureManager::GetInstance()->draw(gobj->sprite->ref, pos.x, pos.y, gobj->sprite->width, gobj->sprite->height, gobj->sprite->currentAnimation->prog, gobj->sprite->currentAnimation->y, sdlRenderer_, SDL_FLIP_NONE);


	//Show what's been drawn
	SDL_RenderPresent(sdlRenderer_);
}


