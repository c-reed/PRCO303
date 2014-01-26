/*
 * Camera.cpp
 *
 *  Created on: 12 Nov 2013
 *      Author: creed
 */

#include "Camera.h"


Camera::Camera() {
	xRes = 0;
	yRes = 0;
	scale = 1.0f;
	position.x = 0.5f;
	position.y = 0.5f;
}


Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

Vector2D* Camera::getPosition() {
	return &position;
}

void Camera::setScale(float scale) {
	this->scale = scale;
}

float Camera::getScale() {
	return scale;
}

Vector2D Camera::getDrawPos(Vector2D* coords) {

	float ratio = xRes / (CAMERA_WIDTH * scale);

	int x, y;
	float xtemp, ytemp;

	xtemp = coords->x - position.x;
	ytemp = coords->y - position.y;

	x = (xRes / 2);
	x += (xtemp * ratio);
	y = (yRes / 2);
	y += (ytemp * ratio);

	Vector2D drawPos ((int)x, (int)y);

	return drawPos;
}

void Camera::init(int x,int y) {
	this->xRes = x;
	this->yRes = y;
}

