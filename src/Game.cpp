/*
 * Game.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Game.h"
#include "Ghost.h"

#include <sdl2/SDL.h>

Game::Game(Factory*& abstractFactory) {
	aFactory = abstractFactory;

}

void Game::start(){
	Ghost* blinky = aFactory->createGhost("Blinky");
	Pacman* pac = aFactory->createPacman();

	bool quit = false;
	SDL_Event e;
	while( !quit )
	{
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
	}
}

