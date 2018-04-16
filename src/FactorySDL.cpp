/*
 * FactorySDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "FactorySDL.h"

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
			sdlRendererTEMP = SDL_CreateRenderer( sdlWindow, -1, SDL_RENDERER_ACCELERATED );
			sdlRenderer = sdlRendererTEMP;
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			} else {
				sdlScreenSurface = SDL_GetWindowSurface( sdlWindow );
			}

			this->ClearScreen();

			loadedSurface = IMG_Load("Assets/sprites.png");
			SDL_SetColorKey(loadedSurface, SDL_TRUE, 0x000000 );

			tileTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, loadedSurface );
		}
	}
}

FactorySDL::~FactorySDL(){

}

Ghost* FactorySDL::createGhost(int type){
	Ghost* ghost = new GhostSDL(type, sdlRendererTEMP, loadedSurface);
	ghost->setFactory(this);
	return ghost;
}

Pacman* FactorySDL::createPacman(){
	Pacman* pacman = new PacmanSDL(sdlRendererTEMP, loadedSurface);
	pacman->setFactory(this);

	return pacman;
}

Tile* FactorySDL::createTile(int x, int y, int type, int width, int height){
	Tile* tile = new TileSDL(sdlRendererTEMP, tileTexture);
	tile->renderTile(x, y, type, width, height);
	return tile;
}

void FactorySDL::DestroyTile(int tile){
	tileMap->DestroyTile(tile);
}

Map* FactorySDL::createMap() {
	tileMap = new Map(this);
	return tileMap;
}

void FactorySDL::ClearScreen(){
	SDL_SetRenderDrawColor( sdlRendererTEMP, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderClear( sdlRendererTEMP );
}

void FactorySDL::UpdateScreen(){
	sdlRenderer = sdlRendererTEMP;
	SDL_RenderPresent( sdlRenderer );
}

SDL_Surface* FactorySDL::getSurface(){
	return loadedSurface;
}

void FactorySDL::quitVis(){
	SDL_DestroyRenderer( sdlRendererTEMP );
	SDL_DestroyRenderer( sdlRenderer );
	SDL_DestroyWindow( sdlWindow );
	sdlRendererTEMP = NULL;
	sdlRenderer = NULL;
	sdlWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
