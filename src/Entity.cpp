/*
 * Entity.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: ruben
 */

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
	delete entityBox;
}

void Entity::SetFactory(Factory* fac){
	aFactory = fac;
	totalTiles = aFactory->GetNumOfTiles();
	screenWidth = aFactory->GetScreenWidth();
	screenHeight = aFactory->GetScreenHeight();
	mWidth = aFactory->GetTileSize();
	mHeight = aFactory->GetTileSize();
}

int* Entity::GetCollisionBox(){
	entityBox[0] = mPosX;
	entityBox[1] = mPosY;
	entityBox[2] = mWidth;
	entityBox[3] = mHeight;

	return entityBox;
}


bool Entity::CheckCollisions(){
	Tile** tileSet = aFactory->GetMapTiles();

	collision = false;
	int* tileBoxInt = 0;

	for(int j = 0; j < totalTiles; j++){ //CHECK TILES
		tileBoxInt = tileSet[j]->GetBoxInt();

		bool tempCollide = aFactory->CheckCollision(this->GetCollisionBox(), tileBoxInt);

		if(!collision && tempCollide){
			if(tileBoxInt[4] > 0 && tileBoxInt[4] <= 6){ //is wall
				collision = true;
			}
			if(isPac){ //entity is pacman
				aFactory->DestroyTile(j);
			}
		}
	}

	delete tileBoxInt;
	return collision;
}
