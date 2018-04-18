/*
 * Game.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef GAME_H_
#define GAME_H_

#include "Factory.h"
#include "Ghost.h"
#include "Map.h"
#include "EventHandlerSDL.h"
#include "EventHandler.h"
#include <time.h>

using namespace std;

class Game {
public:
	Factory* aFactory;
	Game(Factory*& abstractFactory);
	virtual ~Game();
	void start();
protected:
	int numOfGhosts = 4;
	int fps = 30; //best 30
	int mspf = 1000/fps; //ms per f: 30fps --> every 33.3 ms a frame
	int last_frame = 0;
	clock_t ticks = 0;
	int clock_ms = 0; //clock in ms
	int animationSpeed = 3; //every x frames sprite change
	bool quit = false;
};

#endif /* GAME_H_ */
