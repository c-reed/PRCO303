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

    Node* n = new Node(start, 0, start->getFCost(end));
    addToClosedList(n);

	Node* bestNode = 0;
    Node* curNode = 0;

    std::map<int, Node*>::iterator it;

	bool finished = false;

	while (!finished) {
		for(it = openList_.begin(); it != openList_.end(); it++) {
            curNode = it->second;
			if (bestNode) {
                if (curNode->f <= bestNode->f)
                    bestNode = curNode;
			}
			else
			{
                bestNode = curNode;
			}
        }

        if (bestNode->tile == target_)
			finished = true;

        addToClosedList(bestNode);
	}

    return tracePath();
}

void Pathing::addToClosedList(Node* node) {

    closedList_[node->tile->getID()] = node;

	//remove from open list
    openList_.erase(node->tile->getID());

    if (node->tile != target_) {
		Tile* neighbour;
		int neighbourID;
		//iterate through neighbours
		for (int i = 0; i < 8; i++) {
			neighbour = 0;

            neighbourID = node->tile->getNeighbourID((tile_dir)i);

			if (neighbourID >= 0) {
                neighbour = node->tile->getNeighbour((tile_dir)i);
                if (!openList_.count(neighbourID) && neighbour->isTraversable()) {
					//if doesn't exist on the list and is traversable add it
                    Node* newNode = new Node(neighbour, node, neighbour->getFCost(target_));
                    openList_[neighbour->getID()] = newNode;
                }
            }
        }
    }
}

Tile** Pathing::tracePath() {

	std::vector<Tile*> tempList;

    Node* currentNode = closedList_[target_->getID()];

    while(currentNode) {

        tempList.push_back(currentNode->tile);

        currentNode = currentNode->parent;
	}

	return tempList.data();
}
