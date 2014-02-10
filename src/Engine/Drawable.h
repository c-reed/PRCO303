/*
 * Drawable.h
 *
 *  Created on: 10 Feb 2014
 *      Author: creed
 */

#ifndef DRAWABLE_H_
#define DRAWABLE_H_

class Drawable {
public:
	virtual void draw() = 0;
	virtual ~Drawable();
};

#endif /* DRAWABLE_H_ */
