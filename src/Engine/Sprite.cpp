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

	animations_ = (Animation*)malloc(sizeof(Animation) * numAnimations);

	numAnimations_ = numAnimations;
	ref_ = ref;
	width_ = w;
	height_ = h;
	currentAnimation_ = &animations_[0];
	scale_ = 1.0f;
	animIt_ = 0;
}

/*
 * Creates a new animation and adds it to the sprite's
 * animation list. Returns boolean confirmation of success.
 */
bool Sprite::addAnimation(int y, int frames, float fps, bool animated) {



	if (animIt_ < numAnimations_) {

		animations_[animIt_].y = y;
		animations_[animIt_].frames = frames;
		animations_[animIt_].prog = 0;
		animations_[animIt_].fps = fps;
		animations_[animIt_].animated = animated;

	} else {
		return false;
	}

	setAnimation(animIt_);

	animIt_++;

	return true;
}

void Sprite::setAnimation(int animID) {
	currentAnimation_ = &animations_[animID];
}

/*
 * Advances or loops the animation
 */
void Sprite::nextFrame() {

	if (currentAnimation_->prog++ == currentAnimation_->frames - 1) currentAnimation_->prog = 0;
}

void Sprite::setFrame(int frame) {

	if (frame < currentAnimation_->frames) {
		currentAnimation_->prog = frame;
	}

}

std::string Sprite::getRef() {
	return ref_;
}

int Sprite::getHeight() {
	return height_;
}

int Sprite::getWidth() {
	return width_;
}

Animation* Sprite::getCurrentAnimation() {
	return currentAnimation_;
}

Sprite::~Sprite() {

	free(animations_);
}

