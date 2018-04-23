/*
 * PacmanSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "PacmanSDL.h"

PacmanSDL::PacmanSDL(SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface) {
	sdlRenderer = sdlRendererTEMP;
	surface = loadedSurface;
	pacTexture = SDL_CreateTextureFromSurface( sdlRenderer, surface );

	//SPRITES
	//living: 0-2
	//dead: 3-11
	for(int i = 0; i <= 14; i++){
		pacmanSprite[i].x = 455+(16*i);
		pacmanSprite[i].y = 0;
		pacmanSprite[i].w = 15;
		pacmanSprite[i].h = 15;
	}
}

PacmanSDL::~PacmanSDL() {
	// TODO Auto-generated destructor stub
}

void PacmanSDL::Visualize(){
	renderQuad = { mPosX, mPosY, mWidth, mHeight };
	SDL_RenderCopy( sdlRenderer, pacTexture, &pacmanSprite[frame], &renderQuad );
}

void PacmanSDL::Animate(){
	if(living){
		if(collision){ //stuck
			frame = 1;
		}else {
			frame++;
			if(frame > 2){
				frame = 0;
			}
		}
	} else {
		frame++;
		if(frame > 14){
			frame = 2;
		}
	}
}

void PacmanSDL::Move(){
	int tempPosX = mPosX;
	int tempPosY = mPosY;

	this->MoveInDir(direction);
	if(this->checkCollisions()){ //not possible to go to direction
		mPosX = tempPosX;
		mPosY = tempPosY;

		this->MoveInDir(prevDirection); //keep going prev direction
		if(this->checkCollisions()){
			mPosX = tempPosX;
			mPosY = tempPosY;
		}
	} else {
		prevDirection = direction;
	}

	if(mPosX < -20) //pacman went to far
	{
		mPosX = aFactory->GetScreenWidth();
	}
	if(mPosX > aFactory->GetScreenWidth())
	{
		mPosX = -20;
	}

	this->Visualize();
}

void PacmanSDL::MoveInDir(int direction){
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

void PacmanSDL::GotCaptured(Ghost* ghosts[], int numOfGhosts) {
	for(int i = 0; i<numOfGhosts; i++){
		int* ghostBoxInt = ghosts[i]->GetCollisionBox();
		bool captured = aFactory->checkCollision(this->GetCollisionBox(), ghostBoxInt);
		if(captured){
			if(ghosts[i]->GetAttackingState()){
				aFactory->SubtractLives(1);
				living = false;
			} else {
				ghosts[i]->SetLivingState(false);
			}
		}
	}
}


