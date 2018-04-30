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

	type = ghostType;

	ghostSprite[0].w = 15;
	ghostSprite[0].h = 15;
}

GhostSDL::~GhostSDL(){

}

void GhostSDL::Visualize(){
	if(mPosX == 0 && mPosY == 0){ //default setting when factory was unknown
		mPosX = 15*mWidth;
		mPosY = 15*mHeight;
	}
	if(attacking){
		ghostSprite[0].x = 455;
		if(type == 0) {
			ghostSprite[0].y = 64;
		} else if (type == 1) {
			ghostSprite[0].y = 80;
		} else if (type == 2) {
			ghostSprite[0].y = 96;
		} else {
			ghostSprite[0].y = 112;
		}
	} else {
		ghostSprite[0].x = 584;
		if(living){
			ghostSprite[0].y = 64;
		} else {
			ghostSprite[0].y = 80;
		}
	}

	renderQuadG = { mPosX, mPosY, mWidth, mHeight };
	SDL_RenderCopy( sdlRenderer, ghostTexture, &ghostSprite[0], &renderQuadG );
}

void GhostSDL::Move(){ //RANDOM MOVEMENT
	if(living)
	{
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
	} else {
		this->ReturnToCenter();
	}

	if(mPosX < -30) //ghost went to far
	{
		mPosX = aFactory->GetScreenWidth();
	}
	if(mPosX > aFactory->GetScreenWidth())
	{
		mPosX = -30;
	}

	this->Visualize();
}

void GhostSDL::ReturnToCenter(){
	int x = 15*mWidth;
	int y = 15*mHeight;

	this->MoveToCoordinates(x, y);

	if(mPosX == x && mPosY == y){
		living = true;
		attacking = true;
	}
}

void GhostSDL::MoveTo(int x, int y){
	if(living){
		this->MoveToCoordinates(x, y);
	} else {
		this->ReturnToCenter();
	}

	this->Visualize();
}

void GhostSDL::MoveToCoordinates(int x, int y){
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
