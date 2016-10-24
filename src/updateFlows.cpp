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

	for (int y = 0; y < MAP_Y; y++) { //First, the horizontal flows.

		for (int x = 0; x < MAP_X; x++) { //Get the rows of current temps and materials.  Yes, this is horribly inefficient.  Not that it's not X-1 because this is the copy operation.
			tempRow[x] = temps[y][x];
			matRow[x] = materials[y][x];
		}

		if (! updateFlows(MAP_X, tempRow, flowsX[y], matRow, matRef)) return (false); //Update the current row, fail if it should

	}


	NUM tempCol[MAP_Y];
	int matCol[MAP_Y];

	for (int x = 0; x < MAP_X; x++) { //Next the vertical flows

		for (int y = 0; y < MAP_Y; y++) { //Get the columns of current temps and materials.  This time the inefficiency is necessary.
			tempCol[y] = temps[y][x];
			matCol[y] = materials[y][x];
		}

		if (! updateFlows(MAP_Y, tempCol, flowsY[x], matCol, matRef)) return (false); //Update the current col, fail if it should

	}

	return (true);

}


bool updateFlows3D (NUM temps[MAP_Z][MAP_Y][MAP_X],
		NUM flowsX[MAP_Z][MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Z][MAP_Y-1], NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1],
		int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]
	) {

	NUM tempRow[MAP_X];
	int matRow[MAP_X];


	for (int z = 0; z < MAP_Z; z++) { //First, the X axis flows
		for (int y = 0; y < MAP_Y; y++) {

			for (int x = 0; x < MAP_X; x++) { //Get the rows of current temps and materials.  Yes, this is horribly inefficient.  Not that it's not X-1 because this is the copy operation.
						tempRow[x] = temps[z][y][x];
						matRow[x] = materials[z][y][x];
					}

				if (! updateFlows(MAP_X, tempRow, flowsX[z][y], matRow, matRef)) return (false); //Update the current row, fail if it should

		} //End Y loop
	} //End Z loop


	/*

	// This is the inefficient way.  It uses lots and lots of memory.

	NUM tempsX[MAP_Z][MAP_Y][MAP_X]; //Each array here is rotated so that dimension's flow calculator can use it
	NUM tempsY[MAP_X][MAP_Z][MAP_Y]; //i.e. the relevant dimension is last
	NUM tempsZ[MAP_Y][MAP_X][MAP_Z];

	for (int z = 0; z < MAP_Z; z++) { //Copy the rotated arrays
		for (int y = 0; y < MAP_Y; y++) {
			for (int x = 0; x < MAP_X; x++) {
				tempsX[z][y][x] = temps[z][y][x];
				tempsY[x][z][y] = temps[z][y][x];
				tempsZ[y][x][z] = temps[z][y][x];
			}
		}
	}

	*/


}


