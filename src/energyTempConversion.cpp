/*
 * energyTempConversion.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: kevin
 */

#include "energyTempConversion.h"

NUM energy2temp (NUM energy, NUM heatCapacity) /* energy J to Temperature Units */
{
	return energy*1.0 / heatCapacity;
}

NUM temp2energy (NUM temp, NUM heatCapacity) /* Temperature Units */
{
	return temp * heatCapacity;

}


NUM units2c(NUM units) /* units to Celcius */
{
	return units / UNITSPERC;
}

NUM c2units(NUM c) /* Celcius to units */
{
	return c * UNITSPERC;
}

NUM units2w(NUM units)
{
	return units / UNITSPERW;
}

NUM w2units(NUM w)
{
	return w * UNITSPERW;
}

