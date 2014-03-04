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
	virtual ~GameObject();
	Sprite* getSprite();
	Vector2D* getPos();
	Tile* getTile();
	void move(Tile* newLocation);

protected:
	Tile*			location_;
	Sprite*			sprite_;
};

#endif /* GAMEOBJECT_H_ */
