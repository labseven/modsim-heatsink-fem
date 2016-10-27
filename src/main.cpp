/*
 * main.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#include "main.h"
#define DEBUG 1

using namespace std;

int main() {

	material matRef[] = {
			material(true,  -1,           0,        0,            false), //Magic wall.  Zero / negative conductivity is a sign to say don't calculate flows.
			material(false, ALU_CONDUCT, ALU_HCAP, 0,            false), //Aluminum
			material(false, AIR_CONDUCT, AIR_HCAP, AMBIENT_TEMP, true), //New air
			material(true,  ALU_CONDUCT, ALU_HCAP, 100,          false) //Heated Aluminum
	};

	int materials[MAP_Z][MAP_Y][MAP_X];

	NUM currentTemps[MAP_Z][MAP_Y][MAP_X];
	NUM newTemps[MAP_Z][MAP_Y][MAP_X];
	NUM flowsX[MAP_Z][MAP_Y][MAP_X-1];
	NUM flowsY[MAP_X][MAP_Z][MAP_Y-1];
	NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1];



	int rectStart[][3] = {
			{0,  0, 0}, //Magic wall
			{1,  1, 1}, //Top heatsink
			{1, 15, 1}, //Side heatsink
//			{1, 18, 1}, //Heater
//			{1,  1, 4}, //Air
	};

	int rectEnd[][3] = {
			{19, 7, 19},
			{18, 3, 17},
			{18, 17, 6},
//			{18, 18, 6},
//			{18, 14, 6},
	};

	NUM rectTemps[] =     {0, 25, 25/*, 100, 25*/};
	int rectMaterials[] = {0, 1,  1/*,  3,   2*/};

	makeMap(&currentTemps, &materials, 3, rectStart, rectEnd, rectTemps, rectMaterials);

	/*
	const int loopTimes = 1000;
	NUM time = 0;
	NUM deltaTime = 0.001;

	for(int i = 1; i < loopTimes; i++) // Starting at 1 to make time the same as i (exports are on even numbers)
	{
		updateFlows3D(currentTemps, flowsX, flowsY, flowsZ, materials, matRef);
		//updateTemps3D(deltaTime, currentTemps, newTemps, flowsX, flowsY, flowsZ, materials, matRef);
		//moveAir(newTemps, 2, materials, matRef);

		time += deltaTime;
		memcpy(currentTemps, newTemps, sizeof(NUM)*MAP_Y*MAP_X*MAP_Z);

		//printFlows3D(flowsX, flowsY, flowsZ);
		//printTemps3D(newTemps);
	}
	printTemps3D(newTemps);*/

}
