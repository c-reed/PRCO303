/*
 * Universe.h
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#ifndef UNIVERSE_H_
#define UNIVERSE_H_

#include "Tile.h"
#include "GameObject.h"
#include <vector>

class Universe {
public:
	Universe(int, int);
	virtual ~Universe();
	void create();
	int getSizeX();
	int getSizeY();
	Tile** getTileset();
	Tile* getTileAt(Vector2D* location);
	std::vector<GameObject*> gameObjects;

private:
	void initTiles();
	int xDim_, yDim_;
	Tile** tileSet_;
};

#endif /* UNIVERSE_H_ */
