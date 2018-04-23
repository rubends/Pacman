/*
 * GhostSDL.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef GHOSTSDL_H_
#define GHOSTSDL_H_

#include "Ghost.h"
#include <iostream>

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "Factory.h"

using namespace std;

class GhostSDL : public Ghost{
public:
	GhostSDL(int ghostType, SDL_Renderer* sdlRendererTEMP, SDL_Surface* loadedSurface);
	virtual ~GhostSDL();
	void Visualize();
	void Move();
	void MoveTo(int x, int y);
	void ReturnToCenter();
	void MoveToCoordinates(int x, int y);
protected:
	SDL_Renderer* sdlRenderer;
	SDL_Surface* surface;

	SDL_Rect ghostSprite[3];
	SDL_Texture* ghostTexture = NULL;
	SDL_Rect renderQuadG;

	int prevDir[4] = { 1, 1, 1, 1 };
	int dir[4] = { 1, 1, 1, 1 };
	int changeDir = 0;
};

#endif /* GHOSTSDL_H_ */
