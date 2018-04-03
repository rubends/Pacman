/*
 * PacmanSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "PacmanSDL.h"

extern SDL_Renderer* sdlRendererTEMP; //TODO GET FROM FACTORY
extern SDL_Surface* loadedSurface;

PacmanSDL::PacmanSDL() {
	pacTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, loadedSurface );

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

PacmanSDL::~PacmanSDL() {
	// TODO Auto-generated destructor stub
}

void PacmanSDL::visualize(){
	renderQuad = { mPosX, mPosY, mWidth, mHeight };
	renderQuad.w = 40;
	renderQuad.h = 40;
	SDL_RenderCopy( sdlRendererTEMP, pacTexture, &pacmanSprite[frame], &renderQuad );
}

void PacmanSDL::move(int key, Tile* tileSet[]){
	switch(key) //TODO keep going until next possibility
	{
		case 1: //UP
			mPosY -= PACMAN_VEL;
			this->checkCollisions(tileSet, 192);
			if(collision){
				mPosY += PACMAN_VEL;
			}
			pacmanSprite[0].x = 455;
			pacmanSprite[0].y = 32;
			pacmanSprite[1].x = 471;
			pacmanSprite[1].y = 32;
			break;
		case 2: //DOWN
			mPosY += PACMAN_VEL;
			this->checkCollisions(tileSet, 192);
			if(collision){
				mPosY -= PACMAN_VEL;
			}
			pacmanSprite[0].x = 455;
			pacmanSprite[0].y = 48;
			pacmanSprite[1].x = 471;
			pacmanSprite[1].y = 48;
			break;
		case 3: //LEFT
			mPosX -= PACMAN_VEL;
			this->checkCollisions(tileSet, 192);
			if(collision){
				mPosX += PACMAN_VEL;
			}
			pacmanSprite[0].x = 455;
			pacmanSprite[0].y = 16;
			pacmanSprite[1].x = 471;
			pacmanSprite[1].y = 16;
			break;
		case 4: //RIGHT
			mPosX += PACMAN_VEL;
			this->checkCollisions(tileSet, 192);
			if(collision){
				mPosX -= PACMAN_VEL;
			}
			pacmanSprite[0].x = 455;
			pacmanSprite[0].y = 0;
			pacmanSprite[1].x = 471;
			pacmanSprite[1].y = 0;
			break;
		default:
			break;
	}
	if(collision){ //stuck
		frame = 1;
	}else if(fps >= 3){ //Anmation: 3 times slower than movement
		frame--;
		if(frame <= -1){
			frame = 2;
		}
		fps = 0;
	}
	fps++;
	collision = false;

	if(mPosX < 0) //pacman went to far
	{
		mPosX = SCREEN_WIDTH;
	}
	if(mPosX > (SCREEN_WIDTH-40)) //TODO: GET TILE WIDTH
	{
		mPosX = 0;
	}
	if(mPosY > (SCREEN_HEIGHT-40)) //TODO: GET TILE WIDTH
	{
		mPosY = 0;
	}
}

