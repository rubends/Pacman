/*
 * FactorySDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_

#include "Factory.h"
#include "Ghost.h"
#include "GhostSDL.h"
#include "Pacman.h"
#include "PacmanSDL.h"
#include "Tile.h"
#include "TileSDL.h"

class FactorySDL : public Factory{
	public:
		FactorySDL();
		virtual ~FactorySDL();
		Ghost* createGhost(string name);
		Pacman* createPacman();
		Tile* createTile(int x, int y, int type, int width, int height);
		void ClearScreen();
		void quitVis();
	};

#endif /* FACTORYSDL_H_ */
