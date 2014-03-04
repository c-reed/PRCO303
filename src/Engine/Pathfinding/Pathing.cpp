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

	origin_ = start;
	target_ = end;

	addToClosedList(start);

	Node* bestNode = 0;


	std::map<int, Node>::iterator it;

	bool finished = false;

	while (!finished) {
		for(it = openList_.begin(); it != openList_.end(); it++) {
			if (bestNode) {
				if (it->second.f <= bestNode->f)
					bestNode = &(it->second);
			}
			else
			{
				bestNode = &(it->second);
			}
		}

		if (bestNode->tile == target_)
			finished = true;

		addToClosedList(bestNode->tile);
	}




	//backtrack from end to start via closed list, copy into array to return
	return 0;
}

void Pathing::addToClosedList(Tile* tile) {

	Node node = {tile, 0, tile->getFCost(target_->getID())};

	closedList_[tile->getID()] = node;

	//remove from open list
	openList_.erase(tile->getID());

	if (tile != target_) {
		Tile* neighbour;
		int neighbourID;
		//iterate through neighbours
		for (int i = 0; i < 8; i++) {
			neighbour = 0;

			neighbourID = tile->getNeighbourID((tile_dir)i);

			if (neighbourID >= 0) {
				neighbour = tile->getNeighbour((tile_dir)i);
				if (!openList_.count(neighbourID) && neighbour->isTraversable()) {
					//if doesn't exist on the list and is traversable add it
					Node newNode = {neighbour, tile, neighbour->getFCost(target_->getID())};
					openList_[neighbour->getID()] = newNode;
				}
			}
		}
	}
}

Tile** Pathing::tracePath() {

	std::vector<Tile*> tempList;

	Tile* currentTile = target_;

	while(currentTile != origin_) {
		tempList.push_back(currentTile);

		currentTile = closedList_[currentTile->getID()].parent;
	}

	return tempList.data();
}
