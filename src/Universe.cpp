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

	yDim_ = y;
	xDim_ = x;

	tileSet_ = new Tile*[xDim_ * yDim_];

	for (int i = 0; i < xDim_ * yDim_; i++) {
		float x = 0.5f + (float)(i % xDim_);
		float y = 0.5f + (float)(i / yDim_);
		tileSet_[i] = new Tile(i, x, y);
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
	int nwTile = i - xDim_ - 1;
	int	nTile = i - xDim_;
	int neTile = i - xDim_ + 1;
	int eTile = i + 1;
	int seTile = i + xDim_ + 1;
	int	sTile = i + xDim_;
	int swTile = i + xDim_ - 1;
	int wTile = i - 1;

	for(i = 0; i < xDim_ * yDim_; i++) {

		if (i % xDim_ != 0 && nwTile >= 0) {
			tileSet_[i]->setNWTile(tileSet_[nwTile]);
		}

		if (nTile >= 0) {
			tileSet_[i]->setNTile(tileSet_[nTile]);
		}

		if (i % xDim_ != (xDim_-1) && neTile >= 0) {
			tileSet_[i]->setNETile(tileSet_[neTile]);
		}

		if (i % xDim_ != (xDim_-1)) {
			tileSet_[i]->setETile(tileSet_[eTile]);
		}

		if (i % xDim_ != (xDim_-1) && seTile <= xDim_*yDim_) {
			tileSet_[i]->setSETile(tileSet_[seTile]);
		}

		if (sTile <= xDim_*yDim_) {
			tileSet_[i]->setSTile(tileSet_[sTile]);
		}

		if (i % xDim_ != 0 && swTile <= xDim_*yDim_) {
			tileSet_[i]->setSWTile(tileSet_[swTile]);
		}

		if (i % xDim_ != 0) {
			tileSet_[i]->setWTile(tileSet_[wTile]);
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
	return xDim_;
}

int Universe::getSizeY() {
	return yDim_;
}

Tile** Universe::getTileset() {
	return tileSet_;
}
