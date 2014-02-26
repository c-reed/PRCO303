/*
 * GameState.h
 *
 *  Created on: 20 Feb 2014
 *      Author: creed
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameState {
public:
	GameState();
	virtual ~GameState();

	virtual void 	update() = 0;
	virtual void 	render() = 0;
	virtual void 	event() = 0;
};

#endif /* GAMESTATE_H_ */
