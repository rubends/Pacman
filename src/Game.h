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
	void GetSettings();
	void Start();
protected:
	const int NUM_OF_GHOSTS = 4;
	const int FPS = 30; //best 30
	const int MSPF = 1000/FPS; //ms per f: 30FPS --> every 33.3 ms a frame
	const int COUNT_TO_ATTACKING = 5000 / MSPF; // 5 sec / ms per frame = # frames to go
	const int ANIMATION_SPEED = 3; //every x frames sprite change
};

#endif /* GAME_H_ */
