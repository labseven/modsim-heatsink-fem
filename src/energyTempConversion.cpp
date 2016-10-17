/*
 * energyTempConversion.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: kevin
 */

#include "energyTempConversion.h"

#define EANDTTYPE NUM

EANDTTYPE energy2temp (EANDTTYPE energy, EANDTTYPE heatCapacity) /* energy J to Temperature Units */
{
	return energy*1.0 / heatCapacity;
}

EANDTTYPE temp2energy (EANDTTYPE temp, EANDTTYPE heatCapacity) /* Temperature Units */
{
	return temp * heatCapacity;

}


EANDTTYPE units2c(EANDTTYPE units) /* units to Celcius */
{
	return units / UNITSPERC;
}

EANDTTYPE c2units(EANDTTYPE c) /* Celcius to units */
{
	return c * UNITSPERC;
}

EANDTTYPE units2w(EANDTTYPE units)
{
	return units / UNITSPERW;
}

EANDTTYPE w2units(EANDTTYPE w)
{
	return w * UNITSPERW;
}

