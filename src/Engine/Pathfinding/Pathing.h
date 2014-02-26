/*
 * Pathing.h
 *
 *  Created on: 11 Feb 2014
 *      Author: creed
 */

#ifndef PATHING_H_
#define PATHING_H_

#include <vector>
#include "../../Tile.h"

class Pathing {
public:
	virtual ~Pathing();

	void setTargetNode(Tile* target);
	/*
	 * Finds path between start and end points and returns a sequence of nodes
	 * connecting the two points. Returns null if no path is possible
	 */
	Tile** findPath(Tile* start, Tile* end);

private:
	std::vector<Tile*>	openList;
	std::vector<Tile*>	closedList;
	std::vector<Tile*>	fCostMap;

	void 	addToClosedList(Tile* tile);
	int		getIndexOfInList(Tile* tile, std::vector<Tile*>* list);

	Tile*	findLowestCostNode();
};

#endif /* PATHING_H_ */
