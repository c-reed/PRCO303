/*
 * GameObject.cpp
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#include "GameObject.h"


GameObject::GameObject(Tile* location, Sprite* sprite)	:	 location_(location), sprite_(sprite) {}

GameObject::~GameObject() {
	delete sprite_;
	sprite_ = 0;
}

Vector2D* GameObject::getPos() {
    return location_->getWorldCoords();
}

Tile* GameObject::getTile() {
	return location_;
}

Sprite* GameObject::getSprite() {
	return sprite_;
}
