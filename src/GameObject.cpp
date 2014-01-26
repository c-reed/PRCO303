/*
 * GameObject.cpp
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#include "GameObject.h"


GameObject::GameObject(Tile* location, Sprite* sprite) {

	this->sprite = sprite;
	this->location = location;
	this->coords = new Vector2D(location->getCoords()->x, location->getCoords()->y);

}

Vector2D* GameObject::getPos() {
	return coords;
}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
	delete sprite;
	delete coords;
}

