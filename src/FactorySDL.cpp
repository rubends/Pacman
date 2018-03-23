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
//The window renderer
SDL_Renderer* sdlRenderer = NULL;

FactorySDL::FactorySDL(){

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		//Create window
		sdlWindow = SDL_CreateWindow( "PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( sdlWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			sdlRenderer = SDL_CreateRenderer( sdlWindow, -1, SDL_RENDERER_ACCELERATED );
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			} else {
				//Get window surface
				sdlScreenSurface = SDL_GetWindowSurface( sdlWindow );
			}

			this->ClearScreen();
		}
	}
}

FactorySDL::~FactorySDL(){

}

Ghost* FactorySDL::createGhost(string name){
	Ghost* ghost = new GhostSDL;
	ghost->setName(name);
	//ghost->visualize(name);

	return ghost;
}

Pacman* FactorySDL::createPacman(){
	Pacman* pacman = new PacmanSDL;
	//pacman->Visualize();

	return pacman;
}

Tile* FactorySDL::createTile(int x, int y, int type, int width, int height){
	Tile* tile = new TileSDL();
	tile->renderTile(x, y, type, width, height);
	return tile;
}

void FactorySDL::ClearScreen(){
	SDL_RenderClear( sdlRenderer );
	//SDL_FillRect( sdlScreenSurface, NULL, SDL_MapRGB( sdlScreenSurface->format, 0x06, 0x38, 0x61 ) );
	//SDL_RenderPresent( sdlRenderer );
}

void FactorySDL::quitVis(){
	SDL_DestroyWindow( sdlWindow );
	sdlWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
