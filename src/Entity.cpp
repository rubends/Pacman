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
	totalTiles = 0;

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
	totalTiles = aFactory->GetNumOfTiles();
}


bool Entity::checkCollisions(){
	Tile** tileSet = aFactory->getMapTiles();

	collision = false;
	int entityBox[] = { mPosX, mPosY, mWidth, mHeight };
	int* tileBoxInt = 0;

	cout << "ENTITY: " << sizeof(tileSet) << "\n";
	for(int j = 0; j < totalTiles; j++){
		tileBoxInt = tileSet[j]->getBoxInt();
		int tileBox[] = {  tileBoxInt[0], tileBoxInt[1], tileBoxInt[2], tileBoxInt[3] };

		bool tempCollide = aFactory->checkCollision(entityBox, tileBox);

		if(!collision && tempCollide){
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
	//delete tileBoxInt;

	return collision;
}
