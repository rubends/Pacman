/*
 * PacmanSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "PacmanSDL.h"
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>

extern SDL_Renderer* sdlRenderer;
SDL_Surface* loadedSurface;


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Rect pacmanSprite[3];
SDL_Texture* pacTexture = NULL;
SDL_Rect renderQuad;

int mWidth;
int mHeight;

int frame = 0;
int fps = 0;

PacmanSDL::PacmanSDL() {
	cout << "hey";
	SDL_Surface* loadedSurface = IMG_Load("Assets/sprites.png");
	SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0x00, 0x00, 0x00 ) );


}

PacmanSDL::~PacmanSDL() {
	// TODO Auto-generated destructor stub
}

void PacmanSDL::Visualize(){
	SDL_Surface* loadedSurface = IMG_Load("Assets/sprites.png");
	SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0, 0 ) );


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

	renderQuad = { SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3, mWidth, mHeight };
	renderQuad.w = 40;
	renderQuad.h = 40;
}

void PacmanSDL::Animate(){
	if(fps >= 2000000){
		frame++;
		SDL_RenderCopy( sdlRenderer, pacTexture, &pacmanSprite[frame], &renderQuad );
		SDL_RenderPresent( sdlRenderer );

		if(frame >= 2){
			frame = -1;
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
		mPosX -= PACMAN_VEL;
	}
	if(mPosY < 0)
	{
		mPosY -= PACMAN_VEL;
	}

	renderQuad = { mPosX, mPosY, mWidth, mHeight };
	renderQuad.w = 40;
	renderQuad.h = 40;
	SDL_RenderCopy( sdlRenderer, pacTexture, &pacmanSprite[frame], &renderQuad );
	SDL_RenderPresent( sdlRenderer );
}

