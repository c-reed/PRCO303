/*
 * GameObject.h
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Tile.h"
#include "Engine/Vector2D.h"
#include "Engine/Sprite.h"

/*
 * A GameObject represents any object that has a position and visual
 * representation within the game world.
 */
class GameObject {
public:
	GameObject(Tile*, Sprite*);
	Vector2D* getPos();
	virtual ~GameObject();
	Sprite* getSprite();

private:
	Tile *location_;
	Vector2D *coords_;
	Sprite *sprite_;
};

#endif /* GAMEOBJECT_H_ */
