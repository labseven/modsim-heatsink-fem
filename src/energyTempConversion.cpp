/*
 * energyTempConversion.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: kevin
 */

#include "heatsink.h"



NUM energy2temp (NUM energy, NUM specificHeat)
{
	return energy*1.0 / specificHeat;
}

NUM temp2energy (NUM temp, NUM specificHeat)
{
	return temp * specificHeat;

}


NUM units2c(NUM units)
{
	return units / UNITSPERC;
}

NUM c2units(NUM c)
{
	return c * UNITSPERC;
}
