/*
 * Tile.cpp
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#include "Tile.h"

Tile::Tile(int num, float x, float y) {
	weight = num;
	nTile = 0;
	neTile = 0;
	eTile = 0;
	seTile = 0;
	sTile = 0;
	swTile = 0;
	wTile = 0;
	nwTile = 0;

	coords = new Vector2D(x, y);

}

Tile::~Tile() {
	// TODO Auto-generated  stub
}

void Tile::setNTile(Tile* tile) {
	nTile = tile;
}

void Tile::setNETile(Tile* tile) {
	neTile = tile;
}

void Tile::setETile(Tile* tile) {
	eTile = tile;
}

void Tile::setSETile(Tile* tile) {
	seTile = tile;
}

void Tile::setSTile(Tile* tile) {
	sTile = tile;
}

void Tile::setSWTile(Tile* tile) {
	swTile = tile;
}

void Tile::setWTile(Tile* tile) {
	wTile = tile;
}

void Tile::setNWTile(Tile* tile) {
	nwTile = tile;
}

Tile* Tile::getTile(tile_dir dir) {
	switch (dir) {
	case TILE_NORTH:
		return nTile;
		break;
	case TILE_NORTHEAST:
		return neTile;
		break;
	case TILE_EAST:
		return eTile;
		break;
	case TILE_SOUTHEAST:
		return seTile;
		break;
	case TILE_SOUTH:
		return sTile;
		break;
	case TILE_SOUTHWEST:
		return swTile;
		break;
	case TILE_WEST:
		return wTile;
		break;
	case TILE_NORTHWEST:
		return nwTile;
		break;
	default:
		return 0;
	}
}

Vector2D* Tile::getCoords() {
	return coords;
}
