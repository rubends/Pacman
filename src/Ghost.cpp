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


