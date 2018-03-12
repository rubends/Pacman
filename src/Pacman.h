/*
 * Pacman.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include <iostream>
using namespace std;

class Pacman {
public:
	Pacman();
	virtual ~Pacman();
	virtual void visualize() = 0;
};

#endif /* PACMAN_H_ */
