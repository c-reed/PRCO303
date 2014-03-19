/*
 * Camera.cpp
 *
 *  Created on: 12 Nov 2013
 *      Author: creed
 */

#include "Camera.h"


Camera::Camera(int xRes, int yRes)	:	cameraWidth_(32.0f), xRes_(xRes), yRes_(yRes),
										aRatio_((float)xRes / yRes)
{
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

void Camera::setSizeX(float width) {
	cameraWidth_ = width;

	if (cameraWidth_ > 64)
		cameraWidth_ = 64;

	if (cameraWidth_ < 10)
		cameraWidth_ = 10;

	//Use a blank vector to move the camera 0 spaces, checking the new zoom
	//doesn't overlap the edge of the map
	Vector2D* move0 = new Vector2D(0, 0);
	moveCamera(move0);
	delete move0;
}

float Camera::getSizeX() {
	return cameraWidth_;
}

float Camera::getSizeY() {
	return cameraWidth_ / aRatio_;
}

Vector2D Camera::getDrawPos(Vector2D* coords) {

	float ratio = xRes_ / cameraWidth_;

	int x, y;
	float xtemp, ytemp;

    xtemp = (cameraWidth_ / 2) + coords->x - position_.x;
	ytemp = ((cameraWidth_ / aRatio_) / 2) + coords->y - position_.y;

	x = xtemp * ratio;
	y = ytemp * ratio;

	Vector2D drawPos ((int)x, (int)y);

	return drawPos;
}

void Camera::zoomIn() {
	setSizeX(cameraWidth_ + 0.25f);
}

void Camera::zoomOut() {
	setSizeX(cameraWidth_ - 0.25f);
}

void Camera::moveCamera(Vector2D* movement) {

	float cWidth = cameraWidth_;
	float cHeight = cWidth / aRatio_;

	Vector2D newPos(position_.x + movement->x, position_.y + movement->y);

	if (newPos.x < (cWidth / 2) - 2.5f)
		newPos.x = (cWidth / 2) - 2.5f;
	else if (newPos.x > 129.5f - (cWidth / 2))
		newPos.x = 129.5f - (cWidth / 2);

	if (newPos.y < (cHeight / 2) - 2.5f)
		newPos.y = (cHeight / 2) - 2.5f;
	else if (newPos.y > 129.5f - (cHeight / 2))
		newPos.y = 129.5f - (cHeight / 2);

	position_ = newPos;
}

