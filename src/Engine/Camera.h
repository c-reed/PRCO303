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
#include <iostream>
#include <cstdio>

class Camera {
public:
				Camera(int xRes, int yRes);
	virtual 	~Camera();
	void 		setPosition(float, float);
	Vector2D* 	getPosition();
	Vector2D 	getDrawPos(Vector2D* coords);
	Vector2D	getWorldXYFromScreenXY(int x, int y);
	float 		getSizeX();
	float 		getSizeY();
	void		zoomIn();
	void		zoomOut();
	void 		moveCamera(Vector2D* movement);

private:
	void 			setSizeX(float width);
	Vector2D 		position_;
	float 			cameraWidth_;
	int 			xRes_, yRes_;
	const float		aRatio_;

};

#endif /* CAMERA_H_ */
