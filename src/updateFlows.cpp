/*
 * updateFlows.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: neophile
 */

#include "heatsink.h"

//Calculates flow between each pair of cells, given cell temps and materials
bool updateFlows (NUM cellCount, NUM &temps, NUM &flows, NUM &materials, NUM &matRef );


bool updateFlows (NUM cellCount, NUM &temps, NUM &flows, NUM &materials, NUM &matRef ) {

	NUM temp1, temp2, conduction;
	material material1, material2;

	for (int i = 0; i < cellCount-2; i++) { //One fewer than the number of cells

		temp1 = temps[i]; //Get current temperatures from array 'temps'
		temp2 = temps[i+1];
		material1 = matRef[materials[i]];
		material2 = matRef[materials[i]];

		conduction = (material1[1] + material2[1]) / 2 * CELLSIZE; //Factors in material conductivities (/2 for avg), area, and center-to-center dist

		flows[i] = (temp2 - temp1) * conduction; //The division by 2 is to average the conductivities


	}

	return true; //Unless something went wrong/


}
