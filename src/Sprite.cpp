/*
 * Sprite.cpp
 *
 *  Created on: 4 Nov 2013
 *      Author: creed
 */

#include "Sprite.h"

Sprite::Sprite() {
	init("char9", 128, 128, 1);
}

Sprite::Sprite(std::string ref, int w, int h) {

	init(ref, w, h, 1);
}

Sprite::Sprite(std::string ref, int w, int h, int numAnimations) {

	init(ref, w, h, numAnimations);
}

void Sprite::init(std::string ref, int w, int h, int numAnimations) {

	animations = (Animation*)malloc(sizeof(Animation) * numAnimations);

	this->numAnimations = numAnimations;
	this->ref = ref;
	this->width = w;
	this->height = h;
	this->currentAnimation = &animations[0];
	this->scale = 1.0f;
	this->animIt = 0;
}

/*
 * Creates a new animation and adds it to the sprite's
 * animation list. Returns boolean confirmation of success.
 */
bool Sprite::addAnimation(int y, int frames, float fps, bool animated) {



	if (animIt < numAnimations) {

		//animations[animIt] = {y, frames, 0, fps, animated};

	} else {
		return false;
	}

	setAnimation(animIt);

	animIt++;

	return true;
}

void Sprite::setAnimation(int animID) {
	currentAnimation = &animations[animID];
}

/*
 * Advances or loops the animation
 */
void Sprite::nextFrame() {

	if (currentAnimation->prog++ == currentAnimation->frames - 1) currentAnimation->prog = 0;
}

void Sprite::setFrame(int frame) {

	if (frame < currentAnimation->frames) {
		currentAnimation->prog = frame;
	}

}

Sprite::~Sprite() {

	free(animations);
}

