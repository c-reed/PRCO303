/*
 * TextureManager.h
 *
 *  Created on: 1 Nov 2013
 *      Author: creed
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>


//Singleton responsible for loading and storing textures
class TextureManager {
public:
	static TextureManager* GetInstance();
	bool load(std::string filename, std::string ref,	SDL_Renderer* renderer);
	void draw(std::string ref, int x, int y, int wdith, int height, int xFrame, int yFrame, float cameraScale, SDL_Renderer* renderer, SDL_RendererFlip flip);

	/*
	 * Used to store multiple textures mapped to a string for retrieval
	 */
	std::map<std::string, SDL_Texture*> textureMap;

private:
	TextureManager() {};
	virtual ~TextureManager() {};
	static TextureManager* instance;

};

#endif /* TEXTUREMANAGER_H_ */
