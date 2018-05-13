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
#include <sdl2/SDL_ttf.h>

using namespace std;

class FactorySDL : public Factory{
	public:
		FactorySDL();
		virtual ~FactorySDL();
		Ghost* CreateGhost(int type);
		Pacman* CreatePacman();
		Tile* CreateTile(int x, int y, int type, int width, int height);
		Map* CreateMap();
		void UpdateText();
		void ClearScreen();
		void UpdateScreen();
		SDL_Surface* GetSurface();
		void QuitVis();
	protected:
		SDL_Renderer* sdlRendererTEMP;
		SDL_Renderer* sdlRenderer;
		SDL_Surface* loadedSurface;
		SDL_Window* sdlWindow;
		SDL_Surface* sdlScreenSurface;

		TTF_Font* font;
		TTF_Font* fontBig;
		SDL_Color white;
		SDL_Surface* textSurface;
		SDL_Texture* messageTexture;
		SDL_Rect messageRect;

		SDL_Texture* tileTexture;

		std::string printTxt = "";

	};

#endif /* FACTORYSDL_H_ */
