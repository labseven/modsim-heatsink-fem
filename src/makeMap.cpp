/*
 * makeMap.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#include "makeMap.h"
#define DEBUG 0

using namespace std;



bool makeMap(NUM (newTemps)[MAP_Z][MAP_Y][MAP_X], int (newMaterials)[MAP_Z][MAP_Y][MAP_X], int rectCount, int start[][3], int end[][3], NUM temps[], int materials[]) {



	if(DEBUG) {
		cout << "newTemps size: " <<sizeof(newTemps[5][0]) / sizeof(NUM) <<endl;
		cout << "newMaterials size: " <<sizeof(newMaterials[5][0]) / sizeof(int) <<endl;
	}

	for (int rect = 0; rect < rectCount; rect++) { //Pick a prism

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

	/*
	if(DEBUG) {
		for (int rect = 0; rect < rectCount; rect++) { //Pick a prism
			for (int z = start[rect][0]; z < end[rect][0]+1; z++) { //Loop through every cell in the relevant rectangular prism
				for (int y = start[rect][1]; y < end[rect][1]+1; y++) {
					for (int x = start[rect][2]; x < end[rect][2]+1; x++) {

						cout << "Reading cell " <<x <<", " <<y <<", " <<z <<endl;

						if (newTemps[z][y][x] != temps[rect]) {
							cout << "Temperature mismatch." <<endl;
							return false;
						}

						if (newMaterials[z][y][x] != materials[rect]) {
							cout << "Material mismatch." <<endl;
							return false;
						}
					} //x
				} //y
			} //z
		} //rect
	}//debug
	*/


	return true;

}


