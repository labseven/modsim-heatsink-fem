/*
 * energyTempConversion.h
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#ifndef ENERGYTEMPCONVERSION_H_
#define ENERGYTEMPCONVERSION_H_

#include "main.h"

NUM energy2temp (NUM energy, NUM heatCapacity);
NUM temp2energy (NUM temp, NUM heatCapacity);

NUM units2c(NUM units);
NUM c2units(NUM c);

NUM units2w(NUM units);
NUM w2units(NUM w);


#endif /* ENERGYTEMPCONVERSION_H_ */
