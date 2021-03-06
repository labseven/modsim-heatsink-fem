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
#include <string.h>
#include <time.h>


#define NUM double

struct material{
	bool constantTemp;
	NUM conductivity;
	NUM heatCapacity;
	NUM tempSetPoint;
	bool isFluid;

	material(bool constantTempIn, NUM conductivityIn, NUM heatCapacityIn, NUM tempSetPointIn, bool isFluidIn) { //Constructor
		constantTemp = constantTempIn;
		conductivity = conductivityIn;
		heatCapacity = heatCapacityIn;
		tempSetPoint = tempSetPointIn;
		isFluid = isFluidIn;
	}

	material() {}; //Default constructor, for when you are gonna assign values later.

};


#define CELLSIZE 1  //millimeters
#define KELVINOFFSET 273.150
#define DELTATIME .0001 // Seconds


static const NUM ALU_CONDUCT = 205. /*W/mC*/ / 1000 /*mm/m*/;
static const NUM AIR_CONDUCT = 0.024 /*W/mC*/ / 1000 /*mm/m*/;
//static const NUM AIR_CONDUCT = 2.4 /*W/mC*/ / 1000 /*mm/m*/;
static const NUM FLUID_MULT = 1.5; //Unitless.

static const NUM ALU_HCAP = 0.91 /*J/gC*/ * 0.0027 /*g/mm^3*/;
static const NUM AIR_HCAP = 1.005 /*J/gC*/ * 1.2*0.000001 /*g/mm^3*/;

static const NUM AMBIENT_TEMP = 25 /*C*/;

static const NUM AIRSPEED = 3 /*m/s*/ * 1000 /*mm/m*/;


//static const int MAP_Z = 60;
//static const int MAP_Y = 150;
//static const int MAP_X = 60;

#define MAP_Z 30
#define MAP_Y 55
#define MAP_X 11

#include "energyTempConversion.h"
#include "updateFlows.h"
#include "updateTemps.h"
#include "csvExport.h"
#include "print.h"
#include "moveAir.h"
#include "makeMap.h"




#endif /* MAIN_H_ */
