/*
 * TextureManager.cpp
 *
 *  Created on: 1 Nov 2013
 *      Author: creed
 */

#include "TextureManager.h"

TextureManager* TextureManager::instance = 0;

TextureManager* TextureManager::GetInstance() {

		if(instance == 0) {
			instance = new TextureManager();
			return instance;
		} else
			return instance;

	}

bool TextureManager::load(std::string filename, std::string id, SDL_Renderer* renderer) {

	SDL_Surface* tempSurface = IMG_Load(filename.c_str());


	if (tempSurface == NULL)
		return false;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	SDL_FreeSurface(tempSurface);


	if (texture != NULL) {
		textureMap[id] = texture;
		return true;
	}

	return false;

}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
		int xFrame, int yFrame, SDL_Renderer* renderer, SDL_RendererFlip flip) {

	SDL_Rect srcRect, dstRect;

	srcRect.x = width * xFrame;
	srcRect.y = height * yFrame;
	srcRect.w = dstRect.w = width;
	srcRect.h = dstRect.h = height;
	dstRect.x = x - width / 2;
	dstRect.y = y - height / 2;


	SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &dstRect,
			0, 0, flip);

}
