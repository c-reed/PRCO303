/*
 * Game_onRender.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Game.h"
#include "Camera.h"

/*
 * Render the frame
 */
void Game::onRender() {

	SDL_SetRenderDrawColor(sdlRenderer_, 120, 120, 120, 255);

	//clear the screen
	SDL_RenderClear(sdlRenderer_);



	Vector2D pos;


	//render tileset
	Tile** tileset = universe_->getTileset();
	for(int i = 0; i < 128 * 128; i++) {

		pos = camera_->getDrawPos(tileset[i]->getCoords());

		if (pos.x < 1100 &&	pos.x > -50 && pos.y < 590 && pos.y > -50)
		{
		textureManager_->draw("tile", pos.x, pos.y,
											32, 32, 1, 0,
											camera_, sdlRenderer_, SDL_FLIP_NONE);
		}
	}

	//render gameobjects
	GameObject* gobj = universe_->gameObjects.back();
	pos = camera_->getDrawPos(gobj->getPos());
	textureManager_->draw(gobj->getSprite()->getRef(), pos.x, pos.y,
										gobj->getSprite()->getWidth(), gobj->getSprite()->getHeight(),
										gobj->getSprite()->getCurrentAnimation()->prog, gobj->getSprite()->getCurrentAnimation()->y,
										camera_, sdlRenderer_, SDL_FLIP_NONE);


	pos = camera_->getDrawPos(new Vector2D(5.5f, 7.5f));
	textureManager_->draw(gobj->getSprite()->getRef(), pos.x, pos.y,
										gobj->getSprite()->getWidth(), gobj->getSprite()->getHeight(),
										gobj->getSprite()->getCurrentAnimation()->prog, gobj->getSprite()->getCurrentAnimation()->y,
										camera_, sdlRenderer_, SDL_FLIP_NONE);

//	SDL_Color textColor = {0,0,0,255};
//	textManager_->renderText("The quick brown fox rusty gate\nblah blah blah", textColor, sdlRenderer_);


//	Show what's been drawn
	SDL_RenderPresent(sdlRenderer_);
}


