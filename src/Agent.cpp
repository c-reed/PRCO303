/*
 * Agent.cpp
 *
 *  Created on: 4 Nov 2013
 *      Author: creed
 */

#include "Agent.h"


Agent::Agent(Tile* location, Sprite* sprite) : GameObject(location, sprite)
{
    currentTask_ = {"NULL", 0, 0, 0};
}

Agent::~Agent() {
}

void Agent::setTask(std::string name, Tile** path) {
    int steps = sizeof(path) / sizeof(path[0]);
    currentTask_ = {"placeholder task", path, 0, steps};
}

bool Agent::move(Tile* newLocation) {
    if (newLocation->isTraversable()) {
        location_ = newLocation;
        return true;
    } else
        return false;
}

void Agent::update() {
    if (currentTask_.path) {
        if (currentTask_.pathPos < currentTask_.steps) {
            currentTask_.pathPos++;
            if(!move(currentTask_.path[currentTask_.pathPos]))
                currentTask_ = {"NULL", 0, 0, 0};
        }
    }
}

