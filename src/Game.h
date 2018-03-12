/*
 * Game.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef GAME_H_
#define GAME_H_

#include "Factory.h"

class Game {
public:
	Factory* aFactory;
	Game(Factory*& abstractFactory);
	void start();
};

#endif /* GAME_H_ */
