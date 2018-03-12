/*
 * GhostSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "GhostSDL.h"
#include <sdl2/SDL.h>

extern SDL_Window* sdlWindow;
extern SDL_Surface* sdlScreenSurface;

void GhostSDL::visualize(){
	SDL_Surface* gHelloWorld = NULL;
	gHelloWorld = SDL_LoadBMP( "img/hello_world.bmp" );
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "img/hello_world.bmp", SDL_GetError() );
	}

	SDL_BlitSurface( gHelloWorld, NULL, sdlScreenSurface, NULL );
	SDL_UpdateWindowSurface( sdlWindow );
	SDL_Delay( 2000 );

	cout << "\nI'm Visualized.";
}
