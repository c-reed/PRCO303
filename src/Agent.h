/*
 * Agent.h
 *
 *  Created on: 4 Nov 2013
 *      Author: creed
 */

#ifndef AGENT_H_
#define AGENT_H_


#include "GameObject.h"
#include "Engine/Pathfinding/Pathing.h"
#include "Task.h"

/*
 * A GameObject derived class representing entities that can move
 * and "think".
 */
class Agent : public GameObject, public Pathing {
public:
	Agent(Tile*, Sprite*);
	virtual ~Agent();
	void setTask(std::string name, Tile** path);
	void performTask();
    bool move(Tile* newLocation);
    void update();
private:
	Task currentTask_; //TODO turn this into an ordered list or something
};

#endif /* AGENT_H_ */
