/*
 * moveAir.h
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#ifndef MOVEAIR_H_
#define MOVEAIR_H_

#include "main.h"
#include <math.h>

NUM moveAir (NUM temps[MAP_Z][MAP_Y][MAP_X], int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]); //Updates air temperatures in place


#endif /* MOVEAIR_H_ */
