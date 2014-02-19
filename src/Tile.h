/*
 * Tile.h
 *
 *  Created on: 3 Nov 2013
 *      Author: creed
 */

#ifndef TILE_H_
#define TILE_H_

#include <map>
#include "Engine/Vector2D.h"
#include "Engine/Sprite.h"


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

typedef enum {
	TILE_STATUS_OPEN,
	TILE_STATUS_WALL,
	TILE_STATUS_FLOOR,
	TILE_STATUS_DOOR,
	TILE_STATUS_BLOCKED
} tile_status;

class Tile {
public:
					Tile(int num, int tilesetX, int tilesetY);
	virtual 		~Tile();
	void 			setNTile(Tile*);
	void 			setNETile(Tile*);
	void 			setETile(Tile*);
	void 			setSETile(Tile*);
	void 			setSTile(Tile*);
	void 			setSWTile(Tile*);
	void 			setWTile(Tile*);
	void 			setNWTile(Tile*);
	Tile* 			getTile(tile_dir);
	/*
	 * Returns a pointer to a Vector2D object containing the X and Y
	 * world coordinates the tile exists at
	 */
	Vector2D* 		getCoords();
	void 			setStatus(tile_status);
	/*
	 * Pre-calculate H-costs (manhattan method) for all tiles in grid
	 */
	void			calculateHCostMap(Tile** tileset, int size);
	int				calculateHCost(Tile* target);


private:

	int					id_, weight_;
	Tile* 				nTile_,* neTile_,* eTile_,* seTile_,* sTile_,
						* swTile_,* wTile_,* nwTile_;
	int*				hCostMap_;
	Vector2D*			worldCoords_,* gridCoords_;
	tile_status 		tileStatus_;
	Sprite*				sprite_;


};

#endif /* TILE_H_ */
