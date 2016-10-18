/*
 * updateFlows.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: neophile
 */

#include "updateFlows.h"

//Calculates flow between each pair of cells, given cell temps and materials


bool updateFlows (int cellCount, NUM temps[], NUM flows[], int materials[], material matRef[]) {

	NUM temp1, temp2, conduction;
	material  *material1 = NULL, *material2 = NULL;

	std::cout << "updateFlows:\nFlows: ";
	for (int i = 0; i < cellCount-1; i++) { //One fewer than the number of cells

		temp1 = temps[i]; //Get current temperatures from array 'temps'
		temp2 = temps[i+1];
		material1 = &matRef[materials[i]]; //Get relevant materials, because we will use their conductivities
		material2 = &matRef[materials[i+1]];

		if (material1->conductivity == 0 || material2->conductivity == 0) conduction = 0;
		else {
			//std::cout << "1 / " <<material1->conductivity <<" = " <<1/material1->conductivity <<".\n";
			//conduction = 1/(1/(material1->conductivity) + 1/(material2->conductivity)) * CELLSIZE * 2; //Factors in material conductivities, area, and center-to-center dist
			conduction = (material1->conductivity) * (material2->conductivity) / ( (material1->conductivity) + (material2->conductivity) ) * CELLSIZE * 2; //Gets the same result, without dividing by large numbers
		}

		flows[i] = (temp1 - temp2) * conduction; //Units are already dealt with in conduction
		std::cout << flows[i] << "W ";

	}
	std::cout << "\n";

	return true; //Unless something went wrong

}
