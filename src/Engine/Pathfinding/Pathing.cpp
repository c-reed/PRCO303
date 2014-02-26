/*
 * Pathing.cpp
 *
 *  Created on: 11 Feb 2014
 *      Author: creed
 */

#include "Pathing.h"

Pathing::~Pathing() {
	// TODO Auto-generated destructor stub
}

Tile** Pathing::findPath(Tile* start, Tile* end) {

	std::vector<int> fCosts;

	while (openList.size() > 0) {

	}


	return NULL;
}

void Pathing::addToClosedList(Tile* tile) {

	if (openList.size() != 0)
	{
		for (int i = 0; i < (int)openList.size() - 1; i++)
		{
			if (openList[i] == tile) {
				openList.erase(openList.begin() + i);
			}
		}
	}


	closedList.push_back(tile);


	//check adjacent squares on open list
	//add to open list
}

int Pathing::getIndexOfInList(Tile* tile, std::vector<Tile*>* list) {

	for (int i = 0; i < (int)list->size() - 1; i++)
	{

	}

	return -1;
}
