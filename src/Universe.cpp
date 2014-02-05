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
