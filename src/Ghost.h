/*
 * Ghost.h
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#ifndef GHOST_H_
#define GHOST_H_
#include <iostream>
using namespace std;

class Ghost {
public:
	string name;
	Ghost();
	virtual ~Ghost();
	void setName(string givenName);
	virtual void visualize(string name) = 0;
};

#endif /* GHOST_H_ */
