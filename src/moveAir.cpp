/*
 * moveAir.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#include "moveAir.h"
#define DEBUG 0

using namespace std;

bool moveAir (NUM temps[MAP_Z][MAP_Y][MAP_X], int axis, int materials[MAP_Z][MAP_Y][MAP_X], material matRef[]) {

	for (int z = 0; z < MAP_Z; z++) { //Loop through every cell
		for (int y = 0; y < MAP_Y; y++) {
			for (int x = 0; x < MAP_X; x++) {

				if (matRef[materials[z][y][x]]/*this material*/.isFluid) {
					if(DEBUG) cout << "Flowing " <<x <<", " <<y <<", " <<z <<endl;
					if (axis == 0) { //x axis

					} //End x axis


				}

			} //x
		} //y
	} //z


	return true;

}


