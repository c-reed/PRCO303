/*
 * Camera.cpp
 *
 *  Created on: 12 Nov 2013
 *      Author: creed
 */

#include "Camera.h"


Camera::Camera(int xRes, int yRes)	:	position_{0.5f, 0.5f}, scale_(1.0f), xRes_(xRes), yRes_(yRes),
										aRatio_((float)xRes / yRes)
{
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

	if (scale_ > 2.5f)
		scale_ = 2.5f;

	if (scale < 0.2f)
		scale_ = 0.2f;

	//Use a blank vector to move the camera 0 spaces, checking the new zoom
	//doesn't overlap the edge of the map
	Vector2D* move0 = new Vector2D(0, 0);
	moveCamera(move0);
	delete move0;


}

float Camera::getScale() {
	return scale_;
}

Vector2D Camera::getDrawPos(Vector2D* coords) {


	float ratio = xRes_ / (CAMERA_WIDTH * scale_);

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

void Camera::zoomCamera(int step) {

}

void Camera::moveCamera(Vector2D* movement) {

	float cWidth = CAMERA_WIDTH * scale_;
	float cHeight = cWidth / aRatio_;

	Vector2D newPos(position_.x + movement->x, position_.y + movement->y);

	if (newPos.x < (cWidth / 2) - 2.5f)
		newPos.x = (cWidth / 2) - 2.5f;
	else if (newPos.x > 130.5f - (cWidth / 2))
		newPos.x = 130.5f - (cWidth / 2);

	if (newPos.y < (cHeight / 2) - 2.5f)
		newPos.y = (cHeight / 2) - 2.5f;
	else if (newPos.y > 130.5f - (cHeight / 2))
		newPos.y = 130.5f - (cHeight / 2);


	position_ = newPos;

	std::cout << "pos: " << newPos.x << " " << newPos.y << std::endl;
}

