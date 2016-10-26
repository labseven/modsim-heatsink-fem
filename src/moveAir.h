/*
 * moveAir.h
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#ifndef MOVEAIR_H_
#define MOVEAIR_H_

#include "main.h"

bool moveAir (NUM temps[MAP_Z][MAP_Y][MAP_X], int axis, int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]); //Updates air temperatures in place


#endif /* MOVEAIR_H_ */
