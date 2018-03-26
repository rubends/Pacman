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
SDL_Renderer* sdlRenderer = NULL;

FactorySDL::FactorySDL(){

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
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
	ghost->visualize(name);

	return ghost;
}

Pacman* FactorySDL::createPacman(){
	Pacman* pacman = new PacmanSDL(this);
	//pacman->Visualize();

	return pacman;
}

Tile* FactorySDL::createTile(int x, int y, int type, int width, int height){
	Tile* tile = new TileSDL();
	tile->renderTile(x, y, type, width, height);
	return tile;
}

void FactorySDL::ClearScreen(){
	SDL_SetRenderDrawColor( sdlRenderer, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderClear( sdlRenderer );
}

void FactorySDL::UpdateScreen(){
	SDL_RenderPresent( sdlRenderer );
}

bool FactorySDL::checkCollision(SDL_Rect a, SDL_Rect b){
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if( bottomA <= topB )
	{
		return false;
	}

	if( topA >= bottomB )
	{
		return false;
	}

	if( rightA <= leftB )
	{
		return false;
	}

	if( leftA >= rightB )
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

void FactorySDL::quitVis(){
	SDL_DestroyWindow( sdlWindow );
	sdlWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
