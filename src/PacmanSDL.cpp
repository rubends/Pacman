/*
 * PacmanSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "PacmanSDL.h"
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

extern SDL_Window* sdlWindow;
extern SDL_Surface* sdlScreenSurface;

PacmanSDL::PacmanSDL() {
	// TODO Auto-generated constructor stub

}

PacmanSDL::~PacmanSDL() {
	// TODO Auto-generated destructor stub
}

void PacmanSDL::visualize(){
	cout << "\nI'm Visualized.";

	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( "Assets/pacman.png" );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", "Assets/pacman.png", IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, sdlScreenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", "Assets/pacman.png", SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	SDL_BlitSurface( optimizedSurface, NULL, sdlScreenSurface, NULL );
	//Update the surface
	SDL_UpdateWindowSurface( sdlWindow );

}

