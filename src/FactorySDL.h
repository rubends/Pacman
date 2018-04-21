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
//#include <SDL_ttf.h>

using namespace std;

class FactorySDL : public Factory{
	public:
		FactorySDL();
		virtual ~FactorySDL();
		Ghost* createGhost(int type);
		Pacman* createPacman();
		Tile* createTile(int x, int y, int type, int width, int height);
		void DestroyTile(int tile);
		Map* createMap();
		void ClearScreen();
		void UpdateScreen();
		SDL_Surface* getSurface();
		void quitVis();
	protected:
		SDL_Renderer* sdlRendererTEMP;
		SDL_Renderer* sdlRenderer;
		SDL_Surface* loadedSurface;
		SDL_Window* sdlWindow;
		SDL_Surface* sdlScreenSurface;

		SDL_Texture* tileTexture;
	};

#endif /* FACTORYSDL_H_ */
