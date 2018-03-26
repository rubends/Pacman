/*
 * PacmanSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "PacmanSDL.h"
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "FactorySDL.h"

extern SDL_Renderer* sdlRenderer;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Rect pacmanSprite[3];
SDL_Texture* pacTexture = NULL;
SDL_Rect renderQuad;

int mWidth;
int mHeight;

int frame = 0;
int fps = 0;

PacmanSDL::PacmanSDL(FactorySDL* fac) {
	factory = fac;
	loadedSurface = NULL;
	cout << "HAP HAP HAP";
}

PacmanSDL::~PacmanSDL() {
	// TODO Auto-generated destructor stub
}

void PacmanSDL::Load() { //MOET NAAR FACTORYSDL
	loadedSurface = IMG_Load("Assets/sprites.png");
	SDL_SetColorKey(loadedSurface, SDL_TRUE, 0x000000 );
	pacTexture = SDL_CreateTextureFromSurface( sdlRenderer, loadedSurface );

	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;

	pacmanSprite[0].x = 455;
	pacmanSprite[0].y = 0;
	pacmanSprite[0].w = 15;
	pacmanSprite[0].h = 15;

	pacmanSprite[1].x = 471;
	pacmanSprite[1].y = 0;
	pacmanSprite[1].w = 15;
	pacmanSprite[1].h = 15;

	pacmanSprite[2].x = 487;
	pacmanSprite[2].y = 0;
	pacmanSprite[2].w = 15;
	pacmanSprite[2].h = 15;
}

void PacmanSDL::Visualize(){
	renderQuad = { mPosX, mPosY, mWidth, mHeight };
	renderQuad.w = 40;
	renderQuad.h = 40;
	SDL_RenderCopy( sdlRenderer, pacTexture, &pacmanSprite[frame], &renderQuad );
	SDL_RenderPresent( sdlRenderer );
}

void PacmanSDL::Animate(){
	if(fps >= 240){
		frame--;
		if(frame <= 0){
			frame = 3;
		}
		fps = 0;
	}
	fps++;
}

void PacmanSDL::Move(int key){
	switch(key)
	{
		case 1: //UP
			mPosY -= PACMAN_VEL;
			break;
		case 2: //DOWN
			mPosY += PACMAN_VEL;
			break;
		case 3: //LEFT
			mPosX -= PACMAN_VEL;
			break;
		case 4: //RIGHT
			mPosX += PACMAN_VEL;
			break;
		default:
			break;
	}
	if(mPosX < 0) //pacman went to far
	{
		mPosX = SCREEN_WIDTH;
	}
	if(mPosX > (SCREEN_WIDTH-40)) //GET TILE WIDTH
	{
		mPosX = 0;
	}
}

