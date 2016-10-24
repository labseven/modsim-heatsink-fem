/*
 * updateFlows.h
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#ifndef UPDATEFLOWS_H_
#define UPDATEFLOWS_H_

#include "main.h"

bool updateFlows (int cellCount, NUM temps[], NUM flows[], int materials[], material matRef[]);
//Calculates flow between each pair of cells, given cell temps and materials

bool updateFlows2D (NUM temps[MAP_Y][MAP_X], NUM flowsX[MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Y-1], int materials[MAP_Y][MAP_X], material matRef[]);
//2D equivalent of above.

bool updateFlows3D (NUM temps[MAP_Z][MAP_Y][MAP_X],
		NUM flowsX[MAP_Z][MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Z][MAP_Y-1], NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1],
		int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]
	);

#endif /* UPDATEFLOWS_H_ */
