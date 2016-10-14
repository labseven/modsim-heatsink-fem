/*
 * heatsink.h
 *
 *  Created on: Oct 13, 2016
 *      Author: kevin
 */

#ifndef HEATSINK_H_
#define HEATSINK_H_

#include <iostream>

#define NUM long int

typedef struct {
	bool constantTemp;
	NUM conductivity;
	NUM specificHeat;
	NUM tempSetPoint;
}material;

#define CELLSIZE 0.001 //meters
#define KELVINOFFSET 273.150
#define UNITSPERC 2^23
#define UNITSPERW 2^26

#define ALU_CONDUCT 205 /*W/mC*/ * 1000 /*mm/m*/ * UNITSPERW /*units/W*/ / UNITSPERC /*units/C*/
#define AIR_CONDUCT 0.024 /*W/mC*/ * 1000 /*mm/m*/ * UNITSPERW /*units/W*/ / UNITSPERC /*units/C*/

#define ALU_HCAP 0.91 /*J/gC*/ * 0.0027 /*g/mm^3*/ / UNITSPERC /*units/C*/
#define AIR_HCAP 1.005 /*J/gC*/ 1.2*10^-6 /*g/mm^3*/ / UNITSPERC /*units/C*/

#endif /* HEATSINK_H_ */
