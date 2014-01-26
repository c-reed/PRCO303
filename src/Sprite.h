/*
 * Sprite.h
 *
 *  Created on: 4 Nov 2013
 *      Author: creed
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <iostream>
#include <cstdlib>
#include "TextureManager.h"

typedef struct {

	int y, frames, prog;
	float fps;
	bool animated;


} Animation;

/*
 * Contains all the details relating to a sprite, including
 * management of animation frames.
 *
 * Requires an animation to be added before use or shit will break.
 */
class Sprite {
public:
	Sprite();
	Sprite(std::string, int, int, int);
	Sprite(std::string, int, int);
	void nextFrame();
	bool addAnimation(int, int, float, bool);
	void setAnimation(int);
	void setFrame(int);
	std::string ref;
	Animation *currentAnimation;
	int width, height;
	virtual ~Sprite();

private:
	void init(std::string, int, int, int);
	Animation *animations;
	int numAnimations, animIt;
	float scale;
};

#endif /* SPRITE_H_ */
