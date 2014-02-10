/*
 * Agent.h
 *
 *  Created on: 4 Nov 2013
 *      Author: creed
 */

#ifndef AGENT_H_
#define AGENT_H_


#include "GameObject.h"

/*
 * A GameObject derived class representing entities that can move
 * and think.
 */
class Agent : public GameObject {
public:
	Agent(Tile*, Sprite*);
	virtual ~Agent();
	void move(Tile* target);
};

#endif /* AGENT_H_ */
