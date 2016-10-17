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

bool updateTemps(NUM cellCount, NUM dt, NUM currentTemps[], NUM newTemps[], NUM flows[], NUM materials[], material matRef[]);

#endif /* UPDATETEMPS_H_ */
