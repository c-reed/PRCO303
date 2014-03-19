/*
 * Task.h
 *
 *  Created on: 4 Mar 2014
 *      Author: creed
 */

#ifndef TASK_H_
#define TASK_H_

struct Task {
	std::string	name;
	Tile** 		path;
    int         pathPos;
    int         steps;
};

#endif /* TASK_H_ */
