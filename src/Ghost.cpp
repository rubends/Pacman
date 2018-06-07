/*
 * Ghost.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */
#include "Ghost.h"

namespace PACMAN {
	Ghost::Ghost(){
		type = 0;
	}

	Ghost::~Ghost() {
		// TODO Auto-generated destructor stub
	}

	bool Ghost::GetAttackingState() {
		return attacking;
	}

	void Ghost::SetAttackingState(bool attack) {
		if(living){
			attacking = attack;
			flashing = false;
		}
	}

	bool Ghost::GetLivingState() {
		return living;
	}

	void Ghost::SetLivingState(bool live) {
		living = live;
	}

	void Ghost::ResetGhost(){
		mPosX = 15*mWidth;
		mPosY = 15*mHeight;
		living = true;
		attacking = true;
	}

	bool Ghost::GetFlashingState() {
		return flashing;
	}

	bool Ghost::SetFlashingState(bool flash) {
		flashing = flash;
		return flashing;
	}

	void Ghost::Move(){ //RANDOM MOVEMENT
		int velocity = mWidth / ghostVel;

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
					mPosY -= velocity;
					break;
				case 2:
					mPosY += velocity;
					break;
				case 3:
					mPosX -= velocity;
					break;
				case 4:
					mPosX += velocity;
					break;
				default:
					break;
			}

			if(this->CheckCollisions()){ //not possible to go to direction
					mPosX = tempPosX;
					mPosY = tempPosY;

					switch(prevDir[type])
					{
						case 1:
							mPosY -= velocity;
							break;
						case 2:
							mPosY += velocity;
							break;
						case 3:
							mPosX -= velocity;
							break;
						case 4:
							mPosX += velocity;
							break;
						default:
							break;
					}
					if(this->CheckCollisions()){
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
			mPosX = screenWidth;
		}
		if(mPosX > screenWidth)
		{
			mPosX = -30;
		}

		this->Visualize();
	}

	void Ghost::ReturnToCenter(){
		int x = 15*mWidth;
		int y = 15*mHeight;

		this->MoveToCoordinates(x, y);

		if(mPosX == x && mPosY == y){
			living = true;
			attacking = true;
			flashing = false;
		}
	}

	void Ghost::MoveToCoordinates(int x, int y){
		int tempPosX = mPosX;
		int tempPosY = mPosY;
		int velocity = mWidth / ghostVel;

		if(mPosX - x > 0){ //TRY HORIZONTALLY;
			mPosX -= velocity;
		} else if (mPosX - x < 0) {
			mPosX += velocity;
		}

		if(this->CheckCollisions()){
			mPosX = tempPosX;
		}


		if(mPosY - y > 0){ //TRY VERTICALLY
			mPosY -= velocity;
		} else if (mPosY - y < 0){
			mPosY += velocity;
		}

		if(this->CheckCollisions()){
			mPosY = tempPosY;
		}
	}

	void Ghost::MoveTo(int x, int y){
		if(living){
			this->MoveToCoordinates(x, y);
		} else {
			this->ReturnToCenter();
		}

		this->Visualize();
	}
}
