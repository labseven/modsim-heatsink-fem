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
	return energy / heatCapacity;
}

EANDTTYPE temp2energy (EANDTTYPE temp, EANDTTYPE heatCapacity) /* Temperature Units */
{
	return temp * heatCapacity;
}

