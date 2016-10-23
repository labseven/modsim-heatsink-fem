/*
 * updateFlows.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: neophile
 */

#include "updateFlows.h"
#define DEBUG 0

//Calculates flow between each pair of cells, given cell temps and materials


bool updateFlows (int cellCount, NUM temps[], NUM flows[], int materials[], material matRef[]) {

	NUM temp1, temp2, conduction;
	material  *material1 = NULL, *material2 = NULL;

	if(DEBUG) std::cout << "updateFlows:\nFlows: ";
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
		if(DEBUG) std::cout << flows[i] << "W ";

	}
	if(DEBUG) std::cout << "\n";

	return true; //Unless something went wrong

}


bool updateFlows2D (NUM temps[MAP_Y][MAP_X], NUM flowsX[MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Y-1], int materials[MAP_Y][MAP_X], material matRef[]) {

	NUM tempRow[MAP_X];
	int matRow[MAP_X];

	for (int i = 0; i < MAP_Y; i++) { //First, the horizontal flows.

		for (int j = 0; j < MAP_X-1; j++) { //Get the rows of current temps and materials.  Yes, this is horribly inefficient.
			tempRow[j] = temps[i][j];
			matRow[j] = materials[i][j];
		}

		if (! updateFlows(MAP_X, tempRow, flowsX[i], matRow, matRef)) return (false); //Update the current row, fail if it should

	}


	NUM tempCol[MAP_Y];
	int matCol[MAP_Y];

	for (int i = 0; i < MAP_X; i++) { //Next the vertical flows

		for (int j = 0; j < MAP_Y-1; j++) { //Get the columns of current temps and materials.  This time the inefficiency is necessary.
			tempCol[j] = temps[j][i];
			matCol[j] = materials[j][i];
		}

		if (! updateFlows(MAP_Y, tempCol, flowsY[i], matCol, matRef)) return (false); //Update the current col, fail if it should

	}

	return (true);

}
