/*
 * Game.h
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>

#include "../Universe.h"
#include "Camera.h"


class Game {
public:
	Game();
	virtual ~Game();
	/*
	 * Begin execution of the game
	 */
	int onExecute();
	bool onInit();
	/*
	 * Check for and react to SDL Events
	 */
	void onEvent(SDL_Event*);
	void onUpdate();
	void onRender();
	/*
	 * Clean up before finishing
	 */
	void onCleanup();

private:
	/*
	 * Whether the game's running
	 */
	bool 				isRunning_;

	/*
	 * SDL window and renderer for creating pretty visual things
	 */
	SDL_Window*			sdlWindow_;
	SDL_Renderer*		sdlRenderer_;
	Universe*			universe_;
	Camera*				camera_;
	const Uint8*		keystates_; //TODO move to input handler class
};

#endif /* GAME_H_ */
