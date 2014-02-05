/*
 * InputManager.h
 *
 *  Created on: 5 Feb 2014
 *      Author: creed
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "SDL2/SDL.h"

class InputManager {
public:
	InputManager();
	virtual ~InputManager();
	bool isKeyPressed(Uint8 sdlScanCode);
};

#endif /* INPUTMANAGER_H_ */
