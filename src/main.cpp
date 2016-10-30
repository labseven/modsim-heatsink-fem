/*
 * main.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#include "main.h"
#define DEBUG 0

using namespace std;

int main() {

	material matRef[] = {
			material(true,  0,           0,        0,            false), //Magic wall.  Zero / negative conductivity is a sign to say don't calculate flows.
			material(false, ALU_CONDUCT, ALU_HCAP, 0,            false), //Aluminum
			material(false, AIR_CONDUCT, AIR_HCAP, AMBIENT_TEMP, true), //New air
			material(true,  ALU_CONDUCT, ALU_HCAP, 100,          false), //Heated Aluminum
			material(true,  ALU_CONDUCT, ALU_HCAP, 0,            false), //Cooled Aluminum
			};

	int materials[MAP_Z][MAP_Y][MAP_X];

	NUM currentTemps[MAP_Z][MAP_Y][MAP_X];
	NUM newTemps[MAP_Z][MAP_Y][MAP_X];
	NUM flowsX[MAP_Z][MAP_Y][MAP_X-1];
	NUM flowsY[MAP_X][MAP_Z][MAP_Y-1];
	NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1];


	int rectStart[][3] = { //A reasonably-shaped single-fin heatsink.
			{0,  0, 0}, //Magic wall
			{1,  1, 1}, //Air, starts by filling everything
			{1,  6, 1}, //Top heatsink
			{1, -7, 1}, //Side heatsink
			{1, -2, 1}, //Heater
	};

	int rectEnd[][3] = {
			{-1, -1, -1},
			{-2, -2, -2},
			{-2, -3,  6},
			{-2, -3, -2},
			{-2, -2, -2},
	};

	NUM rectTemps[] =     {0, 25, 25, 25, 100};
	int rectMaterials[] = {0,  2,  1,  1,   3};

	/*
	int rectStart[][3] = { //Simple setup to test values
				{0,  0, 0}, //Magic wall
				{1,  1, 1}, //Mostly aluminum
				{1, 18, 1}, //Bottom heater
				{1,  1, 1}, //Top cooler
	};

	int rectEnd[][3] = {
				{19, 19, 7}, //Magic wall
				{18, 18, 6},
				{18, 18, 6},
				{18, 17, 6},
	};

	NUM rectTemps[] =     {0, 50, 100, 0};
	int rectMaterials[] = {0, 1,  3,  4};
	*/

	if(!makeMap(currentTemps, materials, 5, rectStart, rectEnd, rectTemps, rectMaterials)) {
		cout << "makeMap failed." <<endl;
		return(-1);
	}

	const int loopTimes = 10000;
	NUM time = 0;
	NUM deltaTime = 0.001;
	int airspeedDivisor = 4;

	clearPython3D(1);

	for(int i = 1; i < loopTimes; i++) // Starting at 1 to make time the same as i (exports are on even numbers)
	{
		updateFlows3D(currentTemps, flowsX, flowsY, flowsZ, materials, matRef);
		updateTemps3D(deltaTime, currentTemps, newTemps, flowsX, flowsY, flowsZ, materials, matRef);
		if(i % airspeedDivisor == 0) moveAir(newTemps, 2, materials, matRef);

		time += deltaTime;
		memcpy(currentTemps, newTemps, sizeof(NUM)*MAP_Y*MAP_X*MAP_Z);

		//printFlows3D(flowsX, flowsY, flowsZ);
		//printTemps3D(newTemps);
		//Data export goes here
	}

	printFlows3D(flowsX, flowsY, flowsZ);
	printTemps3D(currentTemps);
	exportPython3D(currentTemps, time, 1);

}
