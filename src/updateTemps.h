/*
 * updateTemps.h
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#ifndef UPDATETEMPS_H_
#define UPDATETEMPS_H_

#include "main.h"
#include "energyTempConversion.h"

bool updateTemps(int cellCount, NUM deltaTime, NUM currentTemps[], NUM newTemps[], NUM flows[], int materials[], material matRef[]);
bool updateTemps2D (NUM deltaTime, NUM currentTemps[MAP_Y][MAP_X], NUM newTemps[MAP_Y][MAP_X], NUM flowsX[MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Y-1], int materials[MAP_Y][MAP_X], material matRef[]);

#endif /* UPDATETEMPS_H_ */
