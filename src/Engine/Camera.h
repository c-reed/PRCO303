/*
 * Camera.h
 *
 *  Created on: 12 Nov 2013
 *      Author: creed
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#define CAMERA_WIDTH 32


#include "Vector2D.h"

class Camera {
public:
	Camera();
	virtual ~Camera();
	void setPosition(float, float);
	Vector2D* getPosition();
	void setScale(float);
	Vector2D getDrawPos(Vector2D*);
	float getScale();
	void init(int,int);

private:
	Vector2D position;
	float scale;
	int xRes, yRes;
};

#endif /* CAMERA_H_ */
