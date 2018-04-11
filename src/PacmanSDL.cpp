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
	SDL_RenderCopy( sdlRendererTEMP, pacTexture, &pacmanSprite[frame], &renderQuad );
}

void PacmanSDL::SetDirection(int key){
	if(direction != key){
		direction = key;
	}
}

void PacmanSDL::move(){
	int tempPosX = mPosX;
	int tempPosY = mPosY;
	this->moveInDir(direction);

	if(this->checkCollisions()){ //not possible to go to direction
		mPosX = tempPosX;
		mPosY = tempPosY;

		this->moveInDir(prevDirection); //keep going prev direction
		if(this->checkCollisions()){
			mPosX = tempPosX;
			mPosY = tempPosY;
		}
	} else {
		prevDirection = direction;
	}

	if(collision){ //stuck
		frame = 1;
	}else if(fps >= 3){
		frame--;
		if(frame <= -1){
			frame = 2;
		}
		fps = 0;
	}
	fps++;

	if(mPosX < -30) //pacman went to far
	{
		mPosX = aFactory->GetScreenWidth();
	}
	if(mPosX > aFactory->GetScreenWidth())
	{
		mPosX = -30;
	}
}

void PacmanSDL::moveInDir(int direction){
	switch(direction)
	{
		case 1: //UP
			mPosY -= PACMAN_VEL;

			pacmanSprite[0].x = 455;
			pacmanSprite[1].x = 471;
			pacmanSprite[0].y = 32;
			pacmanSprite[1].y = 32;
			break;
		case 2: //DOWN
			mPosY += PACMAN_VEL;

			pacmanSprite[0].x = 455;
			pacmanSprite[1].x = 471;
			pacmanSprite[0].y = 48;
			pacmanSprite[1].y = 48;
			break;
		case 3: //LEFT
			mPosX -= PACMAN_VEL;
			pacmanSprite[0].x = 455;
			pacmanSprite[1].x = 471;
			pacmanSprite[0].y = 16;
			pacmanSprite[1].y = 16;
			break;
		case 4: //RIGHT
			mPosX += PACMAN_VEL;
			pacmanSprite[0].x = 455;
			pacmanSprite[1].x = 471;
			pacmanSprite[0].y = 0;
			pacmanSprite[1].y = 0;
			break;
		default:
			break;
	}
}


