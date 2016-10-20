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

bool updateFlows2D (NUM temps[MAP_X][MAP_Y], NUM flowsX[MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Y-1], int materials[MAP_X][MAP_Y], material matRef[]);
//2D equivalent of above.

#endif /* UPDATEFLOWS_H_ */
