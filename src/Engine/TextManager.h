/*
 * TextManager.h
 *
 *  Created on: 4 Feb 2014
 *      Author: creed
 */

#ifndef TEXTMANAGER_H_
#define TEXTMANAGER_H_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class TextManager {
public:
	TextManager();
	virtual ~TextManager();
	bool init();
	bool renderText(std::string text, SDL_Color textColor, SDL_Renderer* renderer);
private:
	TTF_Font* font_;
	int width_, height_;
};

#endif /* TEXTMANAGER_H_ */
