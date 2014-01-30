/*
 * Camera.cpp
 *
 *  Created on: 12 Nov 2013
 *      Author: creed
 */

#include "Camera.h"


Camera::Camera() {
	xRes_ = 0;
	yRes_ = 0;
	scale_ = 1.3f;
	position_.x = 0.5f;
	position_.y = 0.5f;
}


Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::setPosition(float x, float y) {
	position_.x = x;
	position_.y = y;
}

Vector2D* Camera::getPosition() {
	return &position_;
}

void Camera::setScale(float scale) {
	scale_ = scale;
}

float Camera::getScale() {
	return scale_;
}

Vector2D Camera::getDrawPos(Vector2D* coords) {

	float ratio = xRes_ / CAMERA_WIDTH;

	int x, y;
	float xtemp, ytemp;

	xtemp = coords->x - position_.x;
	ytemp = coords->y - position_.y;

	x = (xRes_ / 2);
	x += (xtemp * ratio);
	y = (yRes_ / 2);
	y += (ytemp * ratio);

	Vector2D drawPos ((int)x, (int)y);

	return drawPos;
}

void Camera::init(int x,int y) {
	this->xRes_ = x;
	this->yRes_ = y;
}

