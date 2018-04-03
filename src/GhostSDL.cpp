/*
 * GhostSDL.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "GhostSDL.h"

extern SDL_Renderer* sdlRendererTEMP; //TODO GET FROM FACTORY
extern SDL_Surface* loadedSurface;

GhostSDL::GhostSDL(int ghostType){
	ghostTexture = SDL_CreateTextureFromSurface( sdlRendererTEMP, loadedSurface );

	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;

	ghostSprite[0].x = 455;
	ghostSprite[0].w = 15;
	ghostSprite[0].h = 15;

	type = ghostType;
	if(type == 1) {
		ghostSprite[0].y = 64;
		mPosX = 280;
		mPosY = 200;
	} else if (type == 2) {
		ghostSprite[0].y = 80;
		mPosX = 280;
		mPosY = 240;
	} else if (type == 3) {
		ghostSprite[0].y = 96;
		mPosX = 320;
		mPosY = 200;
	} else if (type == 4) {
		ghostSprite[0].y = 112;
		mPosX = 320;
		mPosY = 240;
	}
}

GhostSDL::~GhostSDL(){

}

void GhostSDL::visualize(){
	renderQuadG = { mPosX, mPosY, mWidth, mHeight };

	renderQuadG.w = 40;
	renderQuadG.h = 40;

	SDL_RenderCopy( sdlRendererTEMP, ghostTexture, &ghostSprite[0], &renderQuadG );
}

void GhostSDL::move(Tile* tileSet[]){
	//int randNum = rand()%(4) + 1;
	int randNum = 1;
	this->checkCollisions(tileSet, 192);
	if(collision){
		cout << "COLL \n";
	}
	switch(randNum)
	{
		case 1:
			mPosY -= GHOST_VEL;
			/*this->checkCollisions(tileSet, 192);
			if(collision){
				mPosY += GHOST_VEL;
			}*/
			break;
		case 2:
			mPosY += GHOST_VEL;
			/*this->checkCollisions(tileSet, 192);
			if(collision){
				mPosY -= GHOST_VEL;
			}*/
			break;
		case 3:
			mPosX -= GHOST_VEL;
			/*this->checkCollisions(tileSet, 192);
			if(collision){
				mPosX += GHOST_VEL;
			}*/
			break;
		case 4:
			mPosX += GHOST_VEL;
			/*this->checkCollisions(tileSet, 192);
			if(collision){
				mPosX -= GHOST_VEL;
			}*/
			break;
	}
	if(mPosX < 0)
	{
		mPosX = SCREEN_WIDTH;
	}
	if(mPosX > (SCREEN_WIDTH-40))
	{
		mPosX = 0;
	}
	if(mPosY > (SCREEN_HEIGHT-40))
	{
		mPosY = 0;
	}

}

void GhostSDL::moveTo(int x, int y){
	cout << x << " - " << y << "\n";
	if(mPosX - x > 0){
		mPosX -= GHOST_VEL;
	} else {
		mPosX += GHOST_VEL;
	}
	if(mPosY - y > 0){
		mPosY -= GHOST_VEL;
	} else {
		mPosY += GHOST_VEL;
	}
}
