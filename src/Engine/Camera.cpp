/*
 * Camera.cpp
 *
 *  Created on: 12 Nov 2013
 *      Author: creed
 */

#include "Camera.h"


Camera::Camera(int xRes, int yRes)	:	scale_(1.0f), xRes_(xRes), yRes_(yRes) {
	position_.x = 0.5f;
	position_.y = 0.5f;
}

Camera::~Camera() {
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

void Camera::moveCamera(Vector2D* movement) {

	Vector2D newPos(position_.x + movement->x, position_.y + movement->y);

	if (newPos.x < (CAMERA_WIDTH / 2) - 2.5f)
		newPos.x = (CAMERA_WIDTH / 2) - 2.5f;
	else if (newPos.x > 130.5f - (CAMERA_WIDTH / 2))
		newPos.x = 130.5f - (CAMERA_WIDTH / 2);
;

	position_ = newPos;
}

