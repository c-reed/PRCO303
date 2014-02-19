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
	float x = (float)(id % tilesetX);
	float y = (float)(id / tilesetY);

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

void Tile::setStatus(tile_status tileStatus) {
	tileStatus_ = tileStatus;
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


		hCostMap_[i] = deltaX + deltaY;

	//	std::cout << id_ << " = " << hCostMap_[i] << std::endl;
	}
}

int Tile::calculateHCost(Tile* target) {

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
