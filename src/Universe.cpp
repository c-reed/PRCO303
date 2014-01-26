/*
 * Universe.cpp
 *
 *  Created on: 2 Nov 2013
 *      Author: creed
 */

#include "Universe.h"
#include "GameObject.h"
#include <stdio.h>

Universe::Universe(int x, int y) {

	this->y = y;
	this->x = x;

	tileSet = new Tile*[x * y];

	for (int i = 0; i < x * y; i++) {
		tileSet[i] = new Tile(i, 0.5f + i % x, 0.5f + i / y);
	}

	initTiles();

	/* Test grid - text output
	for (int i = 0; i < x * y; i++) {

		Tile* n;
		Tile* ne;
		Tile* e;
		Tile* se;
		Tile* s;
		Tile* sw;
		Tile* w;
		Tile* nw;

		printf("\nTile: %d\n", tileSet[i]->weight);

		if((n = tileSet[i]->getTile(TILE_NORTH)) != 0) {
			printf("North: %d\n", n->weight);
		} else {
			printf("North: NO TILE\n");
		}

		if((ne = tileSet[i]->getTile(TILE_NORTHEAST)) != 0) {
			printf("North East: %d\n", ne->weight);
		} else {
			printf("North East: NO TILE\n");
		}

		if((e = tileSet[i]->getTile(TILE_EAST)) != 0) {
			printf("East: %d\n", e->weight);
		} else {
			printf("East: NO TILE\n");
		}

		if((se = tileSet[i]->getTile(TILE_SOUTHEAST)) != 0) {
			printf("South East: %d\n", se->weight);
		} else {
			printf("South East: NO TILE\n");
		}

		if((s = tileSet[i]->getTile(TILE_SOUTH)) != 0) {
			printf("South: %d\n", s->weight);
		} else {
			printf("South: NO TILE\n");
		}

		if((sw = tileSet[i]->getTile(TILE_SOUTHWEST)) != 0) {
			printf("South West: %d\n", sw->weight);
		} else {
			printf("South West: NO TILE\n");
		}

		if((w = tileSet[i]->getTile(TILE_WEST)) != 0) {
			printf("West: %d\n", w->weight);
		} else {
			printf("West: NO TILE\n");
		}

		if((nw = tileSet[i]->getTile(TILE_NORTHWEST)) != 0) {
			printf("North West: %d\n", nw->weight);
		} else {
			printf("North West: NO TILE\n");
		}
	}*/
}

Universe::~Universe() {
	// TODO Auto-generated destructor stub
}

void Universe::initTiles() {

	int i = 0;

	//figure out all the tile indexes relative to the starting index (0)
	int nwTile = i - x - 1;
	int	nTile = i - x;
	int neTile = i - x + 1;
	int eTile = i + 1;
	int seTile = i + x + 1;
	int	sTile = i + x;
	int swTile = i + x - 1;
	int wTile = i - 1;

	for(i = 0; i < x * y; i++) {

		if (i % x != 0 && nwTile >= 0) {
			tileSet[i]->setNWTile(tileSet[nwTile]);
		}

		if (nTile >= 0) {
			tileSet[i]->setNTile(tileSet[nTile]);
		}

		if (i % x != (x-1) && neTile >= 0) {
			tileSet[i]->setNETile(tileSet[neTile]);
		}

		if (i % x != (x-1)) {
			tileSet[i]->setETile(tileSet[eTile]);
		}

		if (i % x != (x-1) && seTile <= x*y) {
			tileSet[i]->setSETile(tileSet[seTile]);
		}

		if (sTile <= x*y) {
			tileSet[i]->setSTile(tileSet[sTile]);
		}

		if (i % x != 0 && swTile <= x*y) {
			tileSet[i]->setSWTile(tileSet[swTile]);
		}

		if (i % x != 0) {
			tileSet[i]->setWTile(tileSet[wTile]);
		}


		//shift everything along one
		nwTile++;
		nTile++;
		neTile++;
		eTile++;
		seTile++;
		sTile++;
		swTile++;
		wTile++;

	}
}

int Universe::getSizeX() {
	return x;
}

int Universe::getSizeY() {
	return y;
}

Tile** Universe::getTileset() {
	return tileSet;
}
