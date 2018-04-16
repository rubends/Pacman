/*
 * GhostSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "GhostSDL.h"

GhostSDL::GhostSDL(int ghostType, SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface){
	sdlRenderer = sdlRendererTEMP;
	surface = loadedSurface;
	ghostTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, surface );

	mWidth = 40; //todo get tile size
	mHeight = 40;

	ghostSprite[0].x = 455;
	ghostSprite[0].w = 15;
	ghostSprite[0].h = 15;

	type = ghostType;
	if(type == 0) {
		ghostSprite[0].y = 64;
		mPosX = 280;
		mPosY = 200;
	} else if (type == 1) {
		ghostSprite[0].y = 80;
		mPosX = 280;
		mPosY = 240;
	} else if (type == 2) {
		ghostSprite[0].y = 96;
		mPosX = 320;
		mPosY = 200;
	} else {
		ghostSprite[0].y = 112;
		mPosX = 320;
		mPosY = 240;
	}
}

GhostSDL::~GhostSDL(){

}

void GhostSDL::visualize(){
	renderQuadG = { mPosX, mPosY, mWidth, mHeight };
	SDL_RenderCopy( sdlRenderer, ghostTexture, &ghostSprite[0], &renderQuadG );
}

void GhostSDL::move(){ //RANDOM MOVEMENT
	int tempPosX = mPosX;
	int tempPosY = mPosY;
	if(changeDir >= 15 ){ //after x movements change direction
		dir[type] = rand()%(4) + 1;
		changeDir = 0;
	}
	changeDir++;

	switch(dir[type])
	{
		case 1:
			mPosY -= GHOST_VEL;
			break;
		case 2:
			mPosY += GHOST_VEL;
			break;
		case 3:
			mPosX -= GHOST_VEL;
			break;
		case 4:
			mPosX += GHOST_VEL;
			break;
		default:
			break;
	}

	if(this->checkCollisions()){ //not possible to go to direction
			mPosX = tempPosX;
			mPosY = tempPosY;

			switch(prevDir[type])
			{
				case 1:
					mPosY -= GHOST_VEL;
					break;
				case 2:
					mPosY += GHOST_VEL;
					break;
				case 3:
					mPosX -= GHOST_VEL;
					break;
				case 4:
					mPosX += GHOST_VEL;
					break;
				default:
					break;
			}
			if(this->checkCollisions()){
				mPosX = tempPosX;
				mPosY = tempPosY;
				dir[type] = rand()%(4) + 1; //if stuck, change direction
			}
	} else {
		prevDir[type] = dir[type];
	}

	if(mPosX < -30) //ghost went to far
	{
		mPosX = aFactory->GetScreenWidth();
	}
	if(mPosX > aFactory->GetScreenWidth())
	{
		mPosX = -30;
	}
}

void GhostSDL::moveTo(int x, int y){
	int tempPosX = mPosX;
	int tempPosY = mPosY;

	if(mPosX - x > 0){ //TRY HORIZONTALLY;
		mPosX -= GHOST_VEL;
	} else if (mPosX - x < 0) {
		mPosX += GHOST_VEL;
	}

	if(this->checkCollisions()){
		mPosX = tempPosX;
	}


	if(mPosY - y > 0){ //TRY VERTICALLY
		mPosY -= GHOST_VEL;
	} else if (mPosY - y < 0){
		mPosY += GHOST_VEL;
	}

	if(this->checkCollisions()){
		mPosY = tempPosY;
	}
}
