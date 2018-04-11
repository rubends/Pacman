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

	isPac = 0;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::setFactory(Factory* fac){
	aFactory = fac;
}


bool Entity::checkCollisions(){
	int totalTiles = 192;
	Tile** tileSet = {0}; //array must be initialized with a brace enclosed initializer
	tileSet = aFactory->getMapTiles();
	collision = false;
	for(int j = 0; j <= totalTiles; j++){
		int* tileBoxInt = tileSet[j]->getBoxInt();
		int tileBox[] = {  tileBoxInt[0], tileBoxInt[1], tileBoxInt[2], tileBoxInt[3] };

		int entityBox[] = { mPosX, mPosY, mWidth, mHeight };
		bool tempCollide = aFactory->checkCollision(entityBox, tileBox);

		if(!collision && !tempCollide){
			if(tileBoxInt[4] > 0 && tileBoxInt[4] < 10){ //is wall
				collision = true;
			}
			if(isPac == 1){ //entity is pacman
				if(tileBoxInt[4] == 10){ // PELLET
					aFactory->DestroyTile(j);
				} else if(tileBoxInt[4] == 0){ //PAC-DOT
					aFactory->DestroyTile(j);
				}
			}
		}
	}
	return collision;
}
