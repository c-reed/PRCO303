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
				Camera(int xRes, int yRes);
	virtual 	~Camera();
	void 		setPosition(float, float);
	Vector2D* 	getPosition();
	Vector2D 	getDrawPos(Vector2D*);
	void 		setScale(float);
	float 		getScale();
	void 		moveCamera(Vector2D* movement);
	void 		zoomCameraIn();
	void 		zoomCameraOut();

private:
	Vector2D 	position_;
	float 		scale_;
	int 		xRes_, yRes_;
};

#endif /* CAMERA_H_ */
