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
	std::vector<GameObject*> gameObjects;


private:
	int x, y;
	void initTiles();
	Tile** tileSet;
};

#endif /* UNIVERSE_H_ */
