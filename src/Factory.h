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
#include "Tile.h"
#include "Config.h"
#include "GameContext.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Map;
class Pacman;
class Ghost;
class GameContext;
class Factory {
public:
	Factory();
	virtual ~Factory();

	Config* CreateConfig();
	Map* CreateMap();

	virtual Ghost* CreateGhost(int type) = 0;
	virtual Pacman* CreatePacman() = 0;
	virtual Tile* CreateTile(int x, int y, int type, int width, int height) = 0;
	virtual void CreateVis() = 0;
	virtual GameContext* CreateGameContext() = 0;
protected:
	Map* tileMap;
	GameContext* gContext;
	Config* cFile;
};

#endif /* FACTORY_H_ */
