/*
 * Tile.h
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#ifndef TILE_H_
#define TILE_H_


#include "Vector2D.h"


typedef enum {
	TILE_NORTH = 0,
	TILE_NORTHEAST = 1,
	TILE_EAST = 2,
	TILE_SOUTHEAST = 3,
	TILE_SOUTH = 4,
	TILE_SOUTHWEST = 5,
	TILE_WEST = 6,
	TILE_NORTHWEST = 7
} tile_dir;


class Tile {
public:
	Tile(int, float, float);
	virtual ~Tile();
	void setNTile(Tile*);
	void setNETile(Tile*);
	void setETile(Tile*);
	void setSETile(Tile*);
	void setSTile(Tile*);
	void setSWTile(Tile*);
	void setWTile(Tile*);
	void setNWTile(Tile*);
	Tile* getTile(tile_dir);
	Vector2D* getCoords();

	int weight;

private:
	Tile *nTile, *neTile, *eTile, *seTile, *sTile,
	*swTile, *wTile, *nwTile;
	Vector2D *coords;

};

#endif /* TILE_H_ */
