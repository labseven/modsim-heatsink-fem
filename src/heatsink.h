/*
 * heatsink.h
 *
 *  Created on: Oct 13, 2016
 *      Author: kevin
 */

#ifndef HEATSINK_H_
#define HEATSINK_H_

#define NUM long int

typedef struct {
	bool constantTemp;
	NUM conductivity;
	NUM specificHeat;
	NUM tempSetPoint;
}material;

#define CELLSIZE 0.001 //meters
#define KELVINOFFSET 273.150 // 0 C = 273.150
#define UNITSPERC 2^23 // Units to C

#endif /* HEATSINK_H_ */
