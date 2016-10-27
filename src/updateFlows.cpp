/*
 * updateFlows.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: neophile
 */

#include "updateFlows.h"
#define DEBUG 0

//Calculates flow between each pair of cells, given cell temps and materials

using namespace std;

bool updateFlows (int cellCount, NUM temps[], NUM flows[], bool doFluidMix, int materials[], material matRef[]) {

	NUM temp1, temp2, conduction;
	material  material1, material2;

	//if(DEBUG) std::cout << "updateFlows:\nFlows: ";
	for (int i = 0; i < cellCount-1; i++) { //One fewer than the number of cells

		temp1 = temps[i]; //Get current temperatures from array 'temps'
		temp2 = temps[i+1];
		material1 = matRef[materials[i]]; //Get relevant materials, because we will use their conductivities
		material2 = matRef[materials[i+1]];
		//material1 = matRef[0];
		//material2 = matRef[0];

		if (material1.conductivity <= 0 || material2.conductivity <= 0){ //Zero or negative conductivities represent things that shouldn't be conducted with
			conduction = 0;
			if(DEBUG) std::cout << "nc! ";
		}
		else {
			//std::cout << "1 / " <<material1->conductivity <<" = " <<1/material1->conductivity <<".\n";
			//conduction = 1/(1/(material1->conductivity) + 1/(material2->conductivity)) * CELLSIZE * 2; //Factors in material conductivities, area, and center-to-center dist
			conduction = (material1.conductivity) * (material2.conductivity) / ( (material1.conductivity) + (material2.conductivity) ) * CELLSIZE * 2; //Gets the same result, without dividing by large numbers
		}

		if (doFluidMix && material1.isFluid && material2.isFluid){
			flows[i] = (temp1 - temp2) * conduction * FLUID_MULT; //Multiply when fluid mixing is on and both are fluids
			if(DEBUG) std::cout << "fluid conduction";
		}
		else{
			flows[i] = (temp1 - temp2) * conduction; //Units are already dealt with in conduction
			if(DEBUG) std::cout << "normal conduction";
		}
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

		if (! updateFlows(MAP_X, tempRow, flowsX[y], false, matRow, matRef)) return (false); //No fluid mixing in X

	}


	NUM tempCol[MAP_Y];
	int matCol[MAP_Y];

	for (int x = 0; x < MAP_X; x++) { //Next the vertical flows

		for (int y = 0; y < MAP_Y; y++) { //Get the columns of current temps and materials.  This time the inefficiency is necessary.
			tempCol[y] = temps[y][x];
			matCol[y] = materials[y][x];
		}

		if (! updateFlows(MAP_Y, tempCol, flowsY[x], false, matCol, matRef)) return (false); //No fluid mixing here either

	}

	return (true);

}


bool updateFlows3D (NUM temps[MAP_Z][MAP_Y][MAP_X],
		NUM flowsX[MAP_Z][MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Z][MAP_Y-1], NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1],
		int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]
	) {

	bool fluidMixing[] = {true, true, false}; //X, Y, Z

	if(DEBUG) cout << "Updating X flows..." <<endl;

	NUM tempStripX[MAP_X]; //One-dimensional arrays that updateFlows can eat
	int matStripX[MAP_X];

	for (int z = 0; z < MAP_Z; z++) { //First, the X axis flows
		for (int y = 0; y < MAP_Y; y++) {

			for (int x = 0; x < MAP_X; x++) {
				tempStripX[x] = temps[z][y][x];
				matStripX[x] = materials[z][y][x];
			}

			cout << "Updating x flows with y=" <<y <<" and z=" <<z <<endl;

			if (! updateFlows(MAP_X, tempStripX, flowsX[z][y], fluidMixing[0], matStripX, matRef)) return (false); //Update the current row, fail if it should

		} //End Y loop
	} //End Z loop

	if(DEBUG) cout <<"Updating Y flows..." << endl;

	NUM tempStripY[MAP_Y]; //One-dimensional arrays that updateFlows can eat
	int matStripY[MAP_Y];

	for (int x = 0; x < MAP_X; x++) { //Next the Y axis
		for (int z = 0; z < MAP_Z; z++) {

			for (int y = 0; y < MAP_Y; y++) {
				tempStripY[y] = temps[z][y][x];
				matStripY[y] = materials[z][y][x];
					}

				if (! updateFlows(MAP_Y, tempStripY, flowsY[x][z], fluidMixing[1], matStripY, matRef)) return (false); //Update the current row, fail if it should

		} //End Z loop
	} //End X loop

	if(DEBUG) cout <<"Updating Z flows..." << endl;

	NUM tempStripZ[MAP_Z]; //One-dimensional arrays that updateFlows can eat
	int matStripZ[MAP_Z];

	for (int y = 0; y < MAP_Y; y++) { //And last the Z axis
		for (int x = 0; x < MAP_X; x++) {

			for (int z = 0; z < MAP_Z; z++) {
				tempStripZ[z] = temps[z][y][x];
				matStripZ[z] = materials[z][y][x];
					}

				if (! updateFlows(MAP_Z, tempStripZ, flowsZ[y][x], fluidMixing[2], matStripZ, matRef)) return (false); //Update the current row, fail if it should

		} //End X loop
	} //End Y loop

	if(DEBUG) cout <<"Done updating flows." << endl;

	return true;

}


