/*
 * GameObject.cpp
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#include "GameObject.h"


GameObject::GameObject(Tile* location, Sprite* sprite)	:	 location_(location), sprite_(sprite)
{
}

GameObject::~GameObject() {
	delete sprite_;
}

Vector2D* GameObject::getPos() {
	return location_->getCoords();
}

Tile* GameObject::getTile() {
	return location_;
}

void GameObject::move(Tile* newLocation) {
	location_ = newLocation;
}

Sprite* GameObject::getSprite() {
	return sprite_;
}

