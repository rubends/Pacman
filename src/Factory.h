/*
 * Factory.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Ghost.h"
#include "Pacman.h"
#include "Map.h"
#include "Tile.h"
#include <iostream>
using namespace std;

class Map;
class Pacman;
class Factory {
public:
	Factory();
	virtual ~Factory();
	virtual Ghost* createGhost(int type) = 0;
	virtual Pacman* createPacman() = 0;
	virtual Tile* createTile(int x, int y, int type, int width, int height) = 0;
	virtual Map* createMap() = 0;
	virtual void ClearScreen() = 0;
	virtual void UpdateScreen() = 0;
	bool checkCollision(int* a, int* b);
	virtual void quitVis() = 0;
};

#endif /* FACTORY_H_ */
