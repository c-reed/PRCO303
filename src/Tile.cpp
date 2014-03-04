/*
 * Tile.cpp
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#include "Tile.h"

Tile::Tile(int id, int tilesetX, int tilesetY)	:	id_(id), weight_(0), nTile_(0), neTile_(0), eTile_(0),
													seTile_(0), sTile_(0), swTile_(0), wTile_(0),nwTile_(0),
													hCostMap_(0), tileStatus_(TILE_STATUS_OPEN)
{

	tilesetX_ = tilesetX;
	tilesetY_ = tilesetY;

	float x = (float)(id % tilesetX_);
	float y = (float)(id / tilesetY_);

	gridCoords_ = new Vector2D(x, y);
	worldCoords_ = new Vector2D(x + 0.5f, y + 0.5f);

	sprite_ = new Sprite("tile", 32, 32, 1);
			sprite_->addAnimation(0, 1, 0, false);
			sprite_->setFrame(0);

}

Tile::~Tile() {
	delete worldCoords_;
	delete sprite_;
	delete hCostMap_;

	hCostMap_ = 0;
	sprite_ = 0;
	worldCoords_ = 0;
}

void Tile::setNTile(Tile* tile) {
	nTile_ = tile;
}

void Tile::setNETile(Tile* tile) {
	neTile_ = tile;
}

void Tile::setETile(Tile* tile) {
	eTile_ = tile;
}

void Tile::setSETile(Tile* tile) {
	seTile_ = tile;
}

void Tile::setSTile(Tile* tile) {
	sTile_ = tile;
}

void Tile::setSWTile(Tile* tile) {
	swTile_ = tile;
}

void Tile::setWTile(Tile* tile) {
	wTile_ = tile;
}

void Tile::setNWTile(Tile* tile) {
	nwTile_ = tile;
}

Tile* Tile::getTile(tile_dir dir) {

	switch (dir) {
	case TILE_NORTH:
		return nTile_;
		break;
	case TILE_NORTHEAST:
		return neTile_;
		break;
	case TILE_EAST:
		return eTile_;
		break;
	case TILE_SOUTHEAST:
		return seTile_;
		break;
	case TILE_SOUTH:
		return sTile_;
		break;
	case TILE_SOUTHWEST:
		return swTile_;
		break;
	case TILE_WEST:
		return wTile_;
		break;
	case TILE_NORTHWEST:
		return nwTile_;
		break;
	default:
		return 0;
	}
}

Vector2D* Tile::getCoords() {
	return worldCoords_;
}

int Tile::getID() {
	return id_;
}

Tile* Tile::getNeighbour(tile_dir direction) {

	Tile* neighbour = 0;

	switch (direction)
	{
	case TILE_NORTHWEST:
		neighbour = nwTile_;
		break;

	case TILE_NORTH:
		neighbour = nTile_;
		break;

	case TILE_NORTHEAST:
		neighbour = neTile_;
		break;

	case TILE_EAST:
		neighbour = eTile_;
		break;

	case TILE_SOUTHEAST:
		neighbour = seTile_;
		break;

	case TILE_SOUTH:
		neighbour = sTile_;
		break;

	case TILE_SOUTHWEST:
		neighbour = swTile_;
		break;

	case TILE_WEST:
		neighbour = wTile_;
		break;

	default:
		break;
	}

	return neighbour;
}

int Tile::getNeighbourID(tile_dir direction) {
	Tile* neighbour;

	if ((neighbour = getNeighbour(direction)))
		return neighbour->getID();
	else
		return -1;
}

void Tile::setStatus(tile_status tileStatus) {
	tileStatus_ = tileStatus;
}

bool Tile::isTraversable() {
	if (tileStatus_ == TILE_STATUS_BLOCKED)
		return false;

	return true;
}
void Tile::calculateHCostMap(Tile** tileset, int numTiles) {

	//std::cout << "\nDoing H-costs for tile: " << id_ << std::endl;

	hCostMap_ = (int*)malloc(sizeof(int) * numTiles);

		int deltaX = 0;
		int deltaY = 0;

	for (int i = 0; i < numTiles; i++) {

		deltaX = tileset[i]->getCoords()->x - gridCoords_->x;

		if (deltaX < 0)
			deltaX *= -1;

		deltaY = tileset[i]->getCoords()->y - gridCoords_->y;

		if (deltaY < 0)
			deltaY *= -1;


		hCostMap_[i] = (deltaX + deltaY) * 10;

	//	std::cout << id_ << " = " << hCostMap_[i] << std::endl;
	}
}

int Tile::calculateHCost(Tile* target) {

	//ignoring G (directional movement) costs at this time

	int deltaX = 0;
	int deltaY = 0;

	deltaX = target->getCoords()->x - gridCoords_->x;

	if (deltaX < 0)
		deltaX *= -1;

	deltaY = target->getCoords()->y - gridCoords_->y;

	if (deltaY < 0)
		deltaY *= -1;

	return deltaX + deltaY;
}

int Tile::getFCost(int targetID) {
	return hCostMap_[targetID] + weight_;
}
