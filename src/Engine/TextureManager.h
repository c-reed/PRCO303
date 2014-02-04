/*
 * SpriteManager.h
 *
 *  Created on: 4 Feb 2014
 *      Author: creed
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>


class TextureManager {
public:
	TextureManager();
	virtual ~TextureManager();
	bool load(std::string filename, std::string ref,	SDL_Renderer* renderer);
	void draw(std::string ref, int x, int y, int wdith, int height, int xFrame, int yFrame, float cameraScale, SDL_Renderer* renderer, SDL_RendererFlip flip);
	std::map<std::string, SDL_Texture*> getTextureMap();

private:
	std::map<std::string, SDL_Texture*> textureMap;	//Used to store multiple textures mapped to a string for retrieval



};

#endif /* TEXTUREMANAGER_H_ */
