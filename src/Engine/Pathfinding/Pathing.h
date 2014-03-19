/*
 * Pathing.h
 *
 *  Created on: 11 Feb 2014
 *      Author: creed
 */

#ifndef PATHING_H_
#define PATHING_H_

#include <map>
#include <vector>
#include "../../Tile.h"

struct Node {
	Tile*	tile;
    Node*	parent;
	int		f;

    Node(Tile* tile, Node* parent, int f) : tile(tile), parent(parent), f(f) {}
};

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
	Tile*					origin_;
	Tile*					target_;
    std::map<int, Node*>		openList_;
    std::map<int, Node*>		closedList_;

	/*
	 * Adds next tile to the closed list, performing checks on
	 * adjacent nodes in open list and adding new nodes to the
	 * open list.
	 */
    void 	addToClosedList(Node* node);
	/*
	 *
	 */
	Tile**	tracePath();
};

#endif /* PATHING_H_ */
