/*
 * GameObject.cpp
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#include "GameObject.h"


GameObject::GameObject(Tile* location, Sprite* sprite) {

	sprite_ = sprite;
	location_ = location;
	coords_ = new Vector2D(location_->getCoords()->x, location_->getCoords()->y);

}

Vector2D* GameObject::getPos() {
	return coords_;
}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
	delete sprite_;
	delete coords_;
}

Sprite* GameObject::getSprite() {
	return sprite_;
}

