/*
 * TextManager.cpp
 *
 *  Created on: 4 Feb 2014
 *      Author: creed
 */

#include "TextManager.h"


TextManager::TextManager() :	font_(0), width_(0), height_(0) {
}

TextManager::~TextManager() {
	TTF_Quit();
}

bool TextManager::init() {

	if(TTF_Init() == -1)
		return false;

	if(!(font_ = TTF_OpenFont("assets/unispace.ttf", 16)))
		return false;

	return true;
}

bool TextManager::renderText(std::string text, SDL_Color textColor, SDL_Renderer* renderer) {

	SDL_Surface* textSurface = TTF_RenderText_Solid(font_, text.c_str(), textColor);

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	width_ = textSurface->w;
	height_ = textSurface->h;

	SDL_FreeSurface(textSurface);


	if (textTexture == 0)
		return false;

	SDL_Rect dst = { 100, 100, width_, height_ };

	SDL_RenderCopyEx( renderer, textTexture, NULL, &dst, 0, 0, SDL_FLIP_NONE );

	return true;
}
