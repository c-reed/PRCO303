/*
 * SpriteManager.cpp
 *
 *  Created on: 4 Feb 2014
 *      Author: creed
 */

#include "TextureManager.h"

TextureManager::TextureManager() {
}

TextureManager::~TextureManager() {
	IMG_Quit();
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

void TextureManager::draw(std::string ref, int x, int y, int width, int height,
		int xFrame, int yFrame, float cameraScale, SDL_Renderer* renderer, SDL_RendererFlip flip) {

	SDL_Rect srcRect, dstRect;

	srcRect.x = width * xFrame;
	srcRect.y = height * yFrame;
	srcRect.w = width;
	srcRect.h = height;
	dstRect.w = 32 * cameraScale;
	dstRect.h = 32 * cameraScale;
	dstRect.x = (x - width / 2) * cameraScale;
	dstRect.y = (y - height / 2) * cameraScale;


	SDL_RenderCopyEx(renderer, textureMap[ref],
			&srcRect, &dstRect, 0, 0, flip);

}

std::map<std::string, SDL_Texture*> TextureManager::getTextureMap() {
	return textureMap;
}
