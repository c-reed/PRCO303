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

struct GameTime {
	Uint32 current;
	Uint32 last;
	float deltaT;
};


class Game {
public:
	Game();
	virtual ~Game();
	int 	onExecute(); //Begin game loop
	bool 	onInit();
	void 	onEvent(SDL_Event*); //check for and handle SDL events
	void 	onUpdate();
	void 	onRender();
	void 	onCleanup(); //finish up cleanly
	void	updateGameTime();
	Uint32	getGameTime();
	float 	getDeltaT();
	int		getFrameRate(); //Rough idea only, very inaccurate. Good enough for me.

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
	GameTime gameTime_;
	const Uint8*		keystates_; //TODO move to input handler class


};

#endif /* GAME_H_ */
