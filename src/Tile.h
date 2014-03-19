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


enum tile_dir{
	TILE_NORTH = 0,
	TILE_NORTHEAST = 1,
	TILE_EAST = 2,
	TILE_SOUTHEAST = 3,
	TILE_SOUTH = 4,
	TILE_SOUTHWEST = 5,
	TILE_WEST = 6,
	TILE_NORTHWEST = 7
};

enum tile_status {
	TILE_STATUS_OPEN,
	TILE_STATUS_WALL,
	TILE_STATUS_FLOOR,
	TILE_STATUS_DOOR,
	TILE_STATUS_BLOCKED
};

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
    Vector2D* 		getGridCoords();
    Vector2D*        getWorldCoords();
	int				getID();
	Tile*			getNeighbour(tile_dir);
	int				getNeighbourID(tile_dir);
	void 			setStatus(tile_status);
	bool			isTraversable();
	/*
	 * Pre-calculate H-costs (manhattan method) for all tiles in grid
	 */
	void			calculateHCostMap(Tile** tileset, int size);
    int				getFCost(Tile* target);

private:
    int                 calculateHCost(Tile* target);
	int				 	tilesetX_, tilesetY_;
	int					id_, weight_;
	Tile* 				nTile_,* neTile_,* eTile_,* seTile_,* sTile_,
						* swTile_,* wTile_,* nwTile_;
	int*				hCostMap_;
	Vector2D*			worldCoords_,* gridCoords_;
	tile_status 		tileStatus_;
	Sprite*				sprite_;


};

#endif /* TILE_H_ */
