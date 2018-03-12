/*
 * Ghost.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include <iostream>
#include "Ghost.h"
using namespace std;

Ghost::~Ghost() {
	// TODO Auto-generated destructor stub
}

void Ghost::setName(string givenName){
	name = givenName;
	cout << "\nHello, i'm " << name;
}


