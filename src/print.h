/*
 * print.h
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#ifndef PRINT_H_
#define PRINT_H_

#include "main.h"

bool printTemps(int cellCount, NUM temps[]);
bool printFlows(int cellCount, NUM flows[]);
bool printFlows3D(NUM flowsX[MAP_Z][MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Z][MAP_Y-1], NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1]);
bool printTemps3D(NUM temps[MAP_Z][MAP_Y][MAP_X]);

#endif /* PRINT_H_ */
