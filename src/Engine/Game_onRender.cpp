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

	Tile** tileset = universe_->getTileset();

	GameObject* gobj = universe_->gameObjects.back();

	Vector2D pos = camera_->getDrawPos(gobj->getPos());


	//render tileset

	for(int i = 0; i < 50 * 50; i++) {
		Vector2D pos = camera_->getDrawPos(tileset[i]->getCoords());

		TextureManager::GetInstance()->draw("tile", pos.x, pos.y,
											32, 32, 0, 0,
											camera_->getScale(), sdlRenderer_, SDL_FLIP_NONE);

	}

	//TODO Sort out these fucking sprite sizes
	TextureManager::GetInstance()->draw(gobj->getSprite()->getRef(), pos.x, pos.y,
										gobj->getSprite()->getWidth(), gobj->getSprite()->getHeight(),
										gobj->getSprite()->getCurrentAnimation()->prog, gobj->getSprite()->getCurrentAnimation()->y,
										camera_->getScale(), sdlRenderer_, SDL_FLIP_NONE);


	pos = camera_->getDrawPos(new Vector2D(5.5f, 7.5f));

	TextureManager::GetInstance()->draw(gobj->getSprite()->getRef(), pos.x, pos.y,
										gobj->getSprite()->getWidth(), gobj->getSprite()->getHeight(),
										gobj->getSprite()->getCurrentAnimation()->prog, gobj->getSprite()->getCurrentAnimation()->y,
										camera_->getScale(), sdlRenderer_, SDL_FLIP_NONE);


	//Show what's been drawn
	SDL_RenderPresent(sdlRenderer_);
}


