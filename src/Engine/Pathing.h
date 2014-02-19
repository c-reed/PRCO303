/*
 * Pathing.h
 *
 *  Created on: 11 Feb 2014
 *      Author: creed
 */

#ifndef PATHING_H_
#define PATHING_H_

#include <vector>
#include "../Tile.h"

class Pathing {
public:
	Pathing();
	virtual ~Pathing();
	/*
	 * Finds path between start and end points and returns a sequence of nodes
	 * connecting the two points. Returns null if no path is possible
	 */
	std::vector<Tile*>* findPath(Tile* start, Tile* end);

private:
	Tile*	currentTarget;
	Tile*	currentNode;
	Tile**	openNodeList;
	Tile**	closedNodeList;
	Tile** 	nodePath;
};

#endif /* PATHING_H_ */
