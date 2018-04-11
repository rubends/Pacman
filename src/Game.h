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

using namespace std;

class Game {
public:
	Factory* aFactory;
	Game(Factory*& abstractFactory);
	virtual ~Game();
	void start();
protected:
	int numOfGhosts = 4;
};

#endif /* GAME_H_ */
