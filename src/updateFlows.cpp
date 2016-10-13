/*
 * updateFlows.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: neophile
 */

#include "heatsink.h"

//Calculates flow between each pair of cells, given cell temps and materials
bool updateFlows (NUM cellCount, NUM temps[], NUM flows[], NUM materials[], material matRef[]);


bool updateFlows (NUM cellCount, NUM temps[], NUM flows[], NUM materials[], material matRef[]) {

	NUM temp1, temp2, conduction;
	material material1, material2;

	for (int i = 0; i < cellCount-2; i++) { //One fewer than the number of cells

		temp1 = temps[i]; //Get current temperatures from array 'temps'
		temp2 = temps[i+1];
		material1 = matRef[materials[i]]; //Get relevant materials, because we will use their conductivities
		material2 = matRef[materials[i+1]];

		conduction = (material1.conductivity + material2.conductivity) / 2 * CELLSIZE; //Factors in material conductivities (/2 for avg), area, and center-to-center dist

		flows[i] = (temp2 - temp1) * conduction; //Units are already dealt with in conduction

	}

	return true; //Unless something went wrong

}
