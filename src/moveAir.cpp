/*
 * moveAir.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#include "moveAir.h"
#define DEBUG 0

using namespace std;

NUM moveAir (NUM temps[MAP_Z][MAP_Y][MAP_X], int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]) {

	NUM energy = 0; //Joules

	int prevCell[3]; //Location of the previous cell.

	for (int z = MAP_Z-1; z > 0; z--) { //Loop through every cell, bottom to top, skipping the first and last layers
		for (int y = 0; y < MAP_Y; y++) {
			for (int x = 0; x < MAP_X; x++) {

				if (matRef[materials[z][y][x]].isFluid) { //Only do anything if this material is fluid

					if(!matRef[materials[z+1][y][x]].isFluid) //If the next one down is solid
						energy += temp2energy(temps[z][y][x] - AMBIENT_TEMP, matRef[materials[z][y][x]].heatCapacity);


					if (matRef[materials[z-1][y][x]].isFluid) {
						temps[z][y][x] = temps[z-1][y][x]; //If they're both fluid, just set the temp to that of the previous one
						if(DEBUG) cout << "Setting cell " <<x <<", " <<y <<", " <<z <<" to " <<temps [prevCell[0]] [prevCell[1]] [prevCell[2]] <<endl;
					}
					else
						temps[z][y][x] = matRef[materials[z][y][x]].tempSetPoint; //If the previous cell is solid, consider this an inflow from ambient


				} //End if fluid
				//if(DEBUG) cout << "Cell " <<x <<", " <<y <<", " <<z <<" is not fluid." <<endl;

			} //x
		} //y
	} //z


	return energy;



}


