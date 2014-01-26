/*
 * GameObject.h
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Tile.h"
#include "Vector2D.h"
#include "Sprite.h"

/*
 * A GameObject represents any object that has a position and visual
 * representation within the game world.
 */
class GameObject {
public:
	GameObject(Tile*, Sprite*);
	Vector2D* getPos();
	virtual ~GameObject();
	Tile *location;
	Vector2D *coords;
	Sprite *sprite;
private:

};

#endif /* GAMEOBJECT_H_ */
