/*
 * heatsink.h
 *
 *  Created on: Oct 13, 2016
 *      Author: kevin
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <iostream>
#include <cmath>


#define NUM long int

struct material{
	bool constantTemp;
	NUM conductivity;
	NUM heatCapacity;
	NUM tempSetPoint;

	material(bool constantTempIn, NUM conductivityIn, NUM heatCapacityIn, NUM tempSetPointIn) { //Constructor
		constantTemp = constantTempIn;
		conductivity = conductivityIn;
		heatCapacity = heatCapacityIn;
		tempSetPoint = tempSetPointIn;
	}

	//material() {}; //Default constructor, for when you are gonna assign values later.

};

static const NUM CONSTMULT = pow(2, 16);

#define CELLSIZE 1 * CONSTMULT //millimeters
#define KELVINOFFSET 273.150

//#define UNITSPERC 8388608 //2^23
//#define UNITSPERW 67108864 //2^26
static const NUM UNITSPERC = pow(2, 23); //Notably exempt from all of the constant multiplication
static const NUM UNITSPERW = pow(2, 26);

static const NUM ALU_CONDUCT = 205 /*W/mC*/ / 1000 /*mm/m*/ * UNITSPERW /*units/W*/ / UNITSPERC /*units/C*/ * CONSTMULT;
static const NUM AIR_CONDUCT = 0.024 /*W/mC*/ / 1000 /*mm/m*/ * UNITSPERW /*units/W*/ / UNITSPERC  /*units/C*/ * CONSTMULT;

static const NUM ALU_HCAP = 0.91 /*J/gC*/ * 0.0027 /*g/mm^3*/ * UNITSPERC /*units/C*/* CONSTMULT;
static const NUM AIR_HCAP = 1.005 /*J/gC*/ * 1.2*0.000001 /*g/mm^3*/ * UNITSPERC /*units/C*/ * CONSTMULT;

static const NUM AMBIENT_TEMP = 25 /*C*/ * UNITSPERC /*units/C*/ * CONSTMULT;


#include "energyTempConversion.h"
#include "updateFlows.h"
#include "updateTemps.h"

#endif /* MAIN_H_ */
