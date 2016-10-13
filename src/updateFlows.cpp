/*
 * updateFlows.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: neophile
 */

//Calculates flow between each pair of cells, given cell temps and materials
bool updateFlows (NUM cellCount, NUM &temps, NUM &flows, NUM &materials, NUM &matRef );



bool updateFlows (NUM cellCount, NUM &temps, NUM &flows, NUM &materials, NUM &matRef ) {

	NUM temp1, temp2;
	material material1, material2;

	for (int i = 0; i < cellCount-1; i++) {

		temp1 = temps[i]; //Get current temperatures from array 'temps'
		temp2 = temps[i+1];
		material1 = matRef[materials[i]];
		material2 = matRef[materials[i]];

	}


}
