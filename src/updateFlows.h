/*
 * updateFlows.h
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#ifndef UPDATEFLOWS_H_
#define UPDATEFLOWS_H_

#include "main.h"

bool updateFlows (NUM cellCount, NUM temps[], NUM flows[], int materials[], material matRef[]);
//Calculates flow between each pair of cells, given cell temps and materials


#endif /* UPDATEFLOWS_H_ */
