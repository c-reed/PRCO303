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
	Sprite(std::string ref, int width, int height, int numAnimations);
	Sprite(std::string ref, int width, int height);
	void nextFrame();
	bool addAnimation(int yDim, int numFrames, float fps, bool animated);
	void setAnimation(int);
	void setFrame(int);
	std::string getRef();
	int getHeight();
	int getWidth();
	Animation* getCurrentAnimation();
	virtual ~Sprite();

private:
	void init(std::string, int, int, int);
	Animation* animations_, * currentAnimation_;
	int numAnimations_, animIt_, width_, height_;
	float scale_;
	std::string ref_;
};

#endif /* SPRITE_H_ */
