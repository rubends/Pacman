/*
 * Factory.cpp
 *
 *  Created on: Mar 12, 2018
 *      Author: ruben
 */

#include "Factory.h"

Factory::Factory() {
	tileMap = NULL;
	cFile = NULL;
	gContext = NULL;
}

Factory::~Factory() {
	// TODO Auto-generated destructor stub
}

Config* Factory::CreateConfig() {
	cFile = new Config();
	return cFile;
}

Map* Factory::CreateMap() {
	tileMap = new Map(this, cFile->GetMapName(), cFile->GetTileSize());
	this->CreateVis();
	tileMap->CreateMap();
	return tileMap;
}
