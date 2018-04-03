/*
 * FactorySDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef FACTORYSDL_H_
#define FACTORYSDL_H_

#include "Factory.h"
#include "PacmanSDL.h"
#include "GhostSDL.h"
#include "TileSDL.h"

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

using namespace std;

class FactorySDL : public Factory{
	public:
		FactorySDL();
		virtual ~FactorySDL();
		Ghost* createGhost(int type);
		Pacman* createPacman();
		Tile* createTile(int x, int y, int type, int width, int height);
		Map* createMap();
		void ClearScreen();
		void UpdateScreen();
		SDL_Surface* getSurface();
		void quitVis();
	protected:
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
	};

#endif /* FACTORYSDL_H_ */
