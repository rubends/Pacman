/*
 * Ghost.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */
#include "Ghost.h"

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
	attacking = attack;
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

