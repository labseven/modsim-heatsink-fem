/*
 * makeMap.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#include "makeMap.h"
#define DEBUG 1

using namespace std;



bool makeMap(NUM (newTemps)[MAP_Z][MAP_Y][MAP_X], int (newMaterials)[MAP_Z][MAP_Y][MAP_X], int rectCount, int start[][3], int end[][3], NUM temps[], int materials[]) {


	for (int rect = 0; rect < rectCount; rect++) { //Pick a prism

		for (int axis = 0; axis < 3; axis ++) {

			if (
					start[rect][axis] < 0 ||
					end[rect][axis] < 0 ||
					end[rect][axis] < start[rect][axis] ||
					start[rect][axis] > ((axis == 0)? MAP_Z : ( (axis == 1)? MAP_Y : MAP_X )) - 1 || //Triggers if any start is larger than its relevent dimensional bound
					end[rect][axis] > ((axis == 0)? MAP_Z : ( (axis == 1)? MAP_Y : MAP_X )) - 1//The nested conditional is to select the right dimension
					) {
				if(DEBUG) cout << "Error in " <<((axis == 0)? "Z" : ( (axis == 1)? "y" : "x" )) <<" axis of prism #" <<rect <<endl;
				return(false);
			}

		}

		if(DEBUG) cout << "Starting rectangular prism #" <<rect <<endl;

		for (int z = start[rect][0]; z < end[rect][0]+1; z++) { //Loop through every cell in the relevant rectangular prism
			for (int y = start[rect][1]; y < end[rect][1]+1; y++) {
				for (int x = start[rect][2]; x < end[rect][2]+1; x++) {

					if(DEBUG) cout << "Setting cell " <<x <<", " <<y <<", " <<z <<" to temperature " <<temps[rect] <<" and material #" <<materials[rect] <<endl;

					newTemps[z][y][x] = temps[rect]; //Assign this cell's temp
					newMaterials[z][y][x] = materials[rect]; //and material


				} //x
			} //y
		} //z

	} //rect


	return true;

}


