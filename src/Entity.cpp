/*
 * Entity.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: ruben
 */

#include "Entity.h"
#include "Factory.h"

Entity::Entity() {
	collision = false;
	aFactory = NULL;

	mPosX = 0;
	mPosY = 0;
	mWidth = 0;
	mHeight = 0;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::setFactory(Factory* fac){
	aFactory = fac;
}


void Entity::checkCollisions(Tile* tileSet[], int totalTiles){
	for(int j = 0; j <= totalTiles; j++){
		int *tileBoxInt = tileSet[j]->getBoxInt();
		int tileBox[4] = {  tileBoxInt[0], tileBoxInt[1], tileBoxInt[2], tileBoxInt[3] };

		int entityBox[4] = { mPosX, mPosY, mWidth, mHeight };
		if(tileBoxInt[4] != 0){
			bool tempCollide = aFactory->checkCollision(entityBox, tileBox);

			if(!collision && !tempCollide){
				collision = true;
				if(tileBoxInt[4] == 2){
					tileSet[j]->destroyTile();
				}
			}
		}
	}
}
