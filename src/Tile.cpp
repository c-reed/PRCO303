/*
 * Tile.cpp
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#include "Tile.h"

Tile::Tile(int num, float x, float y)	:	id_(num), weight_(0),
											nTile_(0), neTile_(0), eTile_(0),
											seTile_(0), sTile_(0), swTile_(0),
											wTile_(0),nwTile_(0),
											tileStatus_(TILE_STATUS_OPEN)
{
	coords_ = new Vector2D(x, y);

	sprite_ = new Sprite("tile", 32, 32, 1);
			sprite_->addAnimation(0, 1, 0, false);
			sprite_->setFrame(0);

}

Tile::~Tile() {
	// TODO Auto-generated  stub
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
	return coords_;
}

void Tile::setStatus(tile_status tileStatus) {
	tileStatus_ = tileStatus;
}
