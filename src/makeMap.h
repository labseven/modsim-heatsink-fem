/*
 * makeMap.h
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#ifndef MAKEMAP_H_
#define MAKEMAP_H_

#include "main.h"

bool makeMap(NUM (newTemps)[MAP_Z][MAP_Y][MAP_X], int (newMaterials)[MAP_Z][MAP_Y][MAP_X], int rectCount, int start[][3], int end[][3], NUM temps[], int materials[]);

#endif /* MAKEMAP_H_ */
