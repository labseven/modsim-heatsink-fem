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


	const int loopTimes = 5000;
	NUM deltaTime = 0.001;
	NUM currEnergy = 0;
	int airspeedDivisor = round(CELLSIZE / (AIRSPEED * deltaTime));
	NUM currTime = 0;
	clearPython3D(1); // 1 is edge remove
	clearExportPower();

	currTime = 0;

	int rectStart[][3] = { //Simple setup to test values
				{0,  0, 0}, //Magic wall
				{1,  1, 1}, //Mostly aluminum
				{1, -2, 1}, //Bottom heater
				{1,  1, 1}, //Top cooler
	};

	int rectEnd[][3] = {
				{-1, -1, -1}, //Magic wall
				{-2, -2, -2},
				{-2, -2, -2},
				{-2, 2, -2},
	};

	NUM rectTemps[] =     {0, 50, 100, 0};
	int rectMaterials[] = {0, 1,  3,  4};


	if(!makeMap(currentTemps, materials, 5, rectStart, rectEnd, rectTemps, rectMaterials)) {
		cout << "makeMap failed." <<endl;
		return(-1);
	}

	cout << "Simulation starting..." << endl;
	cout << "loops: " << loopTimes << " deltaTime: " << deltaTime << " total time: " << deltaTime * loopTimes << " airSpeed: " << AIRSPEED << " airspeedDivisor: " << airspeedDivisor << endl;
	exportPython3D(currentTemps, currTime, 1);

	time_t simStartTime;
	time(&simStartTime);

	for(int i = 1; i < loopTimes; i++) // Starting at 1 to make time the same as i (exports are on even numbers)
	{
		updateFlows3D(currentTemps, flowsX, flowsY, flowsZ, materials, matRef);
		updateTemps3D(deltaTime, currentTemps, newTemps, flowsX, flowsY, flowsZ, materials, matRef);
		//if(i % airspeedDivisor == 0) cout << moveAir(newTemps, materials, matRef) / (deltaTime * airspeedDivisor) <<endl; //Average power out
		if(i % airspeedDivisor == 0) {
			currEnergy = moveAir(newTemps, materials, matRef);
			if(DEBUG) cout << currEnergy << endl;
		}

		currTime += deltaTime;
		memcpy(currentTemps, newTemps, sizeof(NUM)*MAP_Y*MAP_X*MAP_Z);
	}

	//printFlows3D(flowsX, flowsY, flowsZ);
	//printTemps3D(currentTemps);
	exportPython3D(currentTemps, currTime, 1);

	cout << "Simulation time: " << difftime(time(NULL), simStartTime) <<" seconds" << endl;


}
