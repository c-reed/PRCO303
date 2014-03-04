/*
 * Agent.cpp
 *
 *  Created on: 4 Nov 2013
 *      Author: creed
 */

#include "Agent.h"


Agent::Agent(Tile* location, Sprite* sprite) : GameObject(location, sprite)
{
}

Agent::~Agent() {
}

void Agent::addTask(std::string name, Tile** path) {
	currentTask_ = {"placeholder task", path};
}
