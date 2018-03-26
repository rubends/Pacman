/*
 * Pacman.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Pacman.h"

Pacman::Pacman() {
	mPosX = 100;
	mPosY = 50;
	mVelX = 0;
	mVelY = 0;

}

Pacman::~Pacman() {
	// TODO Auto-generated destructor stub
}

void Pacman::CheckCollisions(Tile* tileSet[4]){
	for(int j = 0; j <= sizeof(tileSet); j++){
		int *boxDim;
		boxDim = tileSet[j]->getBoxInt();
		cout << *(boxDim + 2) << "\n"; //LEES ARRAY UIT
		/*SDL_Rect box =  { w, &boxDim[1], &boxDim[2], &boxDim[3] };
		bool collide = factory->checkCollision(renderQuad, box);
		cout << collide << "\n";*/
	}
}

