/*
 * FactorySDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "FactorySDL.h"
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* sdlWindow = NULL;
SDL_Surface* sdlScreenSurface = NULL;

FactorySDL::FactorySDL(){

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		//Create window
		sdlWindow = SDL_CreateWindow( "PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( sdlWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			} else {
				//Get window surface
				sdlScreenSurface = SDL_GetWindowSurface( sdlWindow );
			}

			//Fill the surface white
			SDL_FillRect( sdlScreenSurface, NULL, SDL_MapRGB( sdlScreenSurface->format, 0x06, 0x38, 0x61 ) );

			//Update the surface
			SDL_UpdateWindowSurface( sdlWindow );
		}
	}
}

FactorySDL::~FactorySDL(){

}

Ghost* FactorySDL::createGhost(string name){
	Ghost* ghost = new GhostSDL;
	ghost->setName(name);
	ghost->visualize(name);

	return ghost;
}

Pacman* FactorySDL::createPacman(){
	Pacman* pacman = new PacmanSDL;
	pacman->visualize();

	return pacman;
}
