/*
 * Pacman.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Pacman.h"

Pacman::Pacman() {
	mPosX = 20*13; // todo get variable
	mPosY = 20*24;

	isPac = true;
}

Pacman::~Pacman() {
	// TODO Auto-generated destructor stub
}

int Pacman::GetX() {
	return mPosX;
}

int Pacman::GetY() {
	return mPosY;
}

void Pacman::SetDirection(int key){
	if(direction != key){
		direction = key;
	}
}

bool Pacman::GetLiving(){
	return living;
}

bool Pacman::SetLiving(bool alive){
	living = alive;
	if(alive){
		mPosX = 20*13; //todo get variable
		mPosY = 20*24;
	}
	return living;
}

void Pacman::Animate(){
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

void Pacman::Move(){
	int tempPosX = mPosX;
	int tempPosY = mPosY;

	this->MoveInDir(direction);
	if(this->CheckCollisions()){ //not possible to go to direction
		mPosX = tempPosX;
		mPosY = tempPosY;

		this->MoveInDir(prevDirection); //keep going prev direction
		if(this->CheckCollisions()){
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

void Pacman::GotCaptured(Ghost* ghosts[], int numOfGhosts) {
	for(int i = 0; i<numOfGhosts; i++){
		int* ghostBoxInt = ghosts[i]->GetCollisionBox();
		bool captured = aFactory->CheckCollision(this->GetCollisionBox(), ghostBoxInt);
		if(captured){
			if(ghosts[i]->GetAttackingState()){
				aFactory->SubtractLives(1);
				aFactory->SetPlaying(false, "Dead");
				living = false;
			} else {
				ghosts[i]->SetLivingState(false);
			}
		}
	}
}
