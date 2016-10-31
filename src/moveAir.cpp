/*
 * moveAir.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#include "moveAir.h"
#define DEBUG 1

using namespace std;

NUM moveAir (NUM temps[MAP_Z][MAP_Y][MAP_X], int axis, int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]) {

	NUM energy = 0; //Joules


	//Now for the ugly bit.  Output the energy that's being lost by the system.


	{
		int z = MAP_Z - 2; //The index of the second-to-last layer

		for (int y = 0; y < MAP_Y; y++) {
				for (int x = 0; x < MAP_X; x++) {
					if (matRef[materials[z][y][x]]/*this material*/.isFluid) {
						energy += temp2energy(temps[z][y][x] - AMBIENT_TEMP, matRef[materials[z][y][x]].heatCapacity);
						//if(DEBUG) cout << "Adding temperature " <<temps[z][y][x] <<" at " <<x <<", " <<y <<", " <<z <<endl;
					} //If fluid
					//else if(DEBUG) cout << "Skipping temperature " <<temps[z][y][x] <<" at " <<x <<", " <<y <<", " <<z <<endl;
				} //x loop
		} //y loop


	}//End ugliness



	int prevCell[3]; //Location of the previous cell.

	for (int z = MAP_Z; z > 0; z--) { //Loop through every cell
		for (int y = 0; y < MAP_Y; y++) {
			for (int x = 0; x < MAP_X; x++) {

				if (matRef[materials[z][y][x]]/*this material*/.isFluid) { //Only do anything if this material is fluid
					//if(DEBUG) cout << "Flowing " <<x <<", " <<y <<", " <<z <<endl;


					if (axis == 0) { //x axis
						prevCell[0] = z;
						prevCell[1] = y;
						prevCell[2] = x-1;
					} //End x axis
					else if (axis == 1) { //y axis
						prevCell[0] = z;
						prevCell[1] = y-1;
						prevCell[2] = x;
					} //End x axis
					else if (axis == 2) { //z axis
						prevCell[0] = z-1;
						prevCell[1] = y;
						prevCell[2] = x;
					} //End x axis
					else {
						cout << "Axis must be between 0 and 2." <<endl;
						return false;
					}

					if(DEBUG) cout << "Prev. cell is " <<prevCell[2] <<", " <<prevCell[1] <<", " <<prevCell[0] <<endl;

					if (matRef[materials [prevCell[0]] [prevCell[1]] [prevCell[2]] ].isFluid) {
						temps[z][y][x] = temps [prevCell[0]] [prevCell[1]] [prevCell[2]]; //If they're both fluid, just set the temp to that of the previous one
						if(DEBUG) cout << "Setting cell " <<x <<", " <<y <<", " <<z <<" to " <<temps [prevCell[0]] [prevCell[1]] [prevCell[2]] <<endl;
					}
					else
						temps[z][y][x] = matRef[materials[z][y][x]].tempSetPoint; //If the previous cell is solid, consider this an inflow from ambient


				} //End if fluid
				if(DEBUG) cout << "Cell " <<x <<", " <<y <<", " <<z <<" is not fluid." <<endl;

			} //x
		} //y
	} //z




	return energy;



}


