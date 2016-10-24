/*
 * main.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#include "main.h"
#define DEBUG 0

using namespace std;

bool printTemps(int cellCount, NUM temps[])
{
	std::cout << "Temperatures: ";
	for (int i = 0; i < cellCount; i++)
	{
		std::cout << temps[i] << "C ";
	}

	std::cout << "\n";
	return true;
}

bool printFlows(int cellCount, NUM flows[])
{
	std::cout << "Flows: ";
	for (int i = 0; i < cellCount; i++)
	{
		std::cout << flows[i] << "W ";
	}

	std::cout << "\n";
	return true;
}

bool printFlows3D(NUM flowsX[MAP_Z][MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Z][MAP_Y-1], NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1]) {

	cout << "X:";

	for (int z = 0; z < MAP_Z; z++) { //First, the X axis flows
		for (int y = 0; y < MAP_Y; y++) {
			for (int x = 0; x < MAP_X-1; x++) {
				cout <<flowsX[z][y][x] <<", ";
			} //End x
			cout <<endl;
		} //End y
		cout <<endl <<endl;
	}//End z

	cout <<endl <<"Y:" <<endl;

	for (int x = 0; x < MAP_X; x++) { //First, the X axis flows
		for (int z = 0; z < MAP_Z; z++) {
			for (int y = 0; y < MAP_Y-1; y++) {
				cout <<flowsY[x][z][y] <<", ";
			} //End y
			cout <<endl;
		} //End z
		cout <<endl <<endl;
	}//End x

	cout <<endl <<"Z:" <<endl;

		for (int y = 0; y < MAP_Y; y++) { //First, the X axis flows
			for (int x = 0; x < MAP_X; x++) {
				for (int z = 0; z < MAP_Z-1; z++) {
					cout <<flowsZ[y][x][z] <<", ";
				} //End z
				cout <<endl;
			} //End x
			cout <<endl <<endl;
		}//End y

		return true;


} //end function

int main() {

	material matRef[] = {
			material(true, 0, 0, 0), //Magic wall.  Yes, this will cause division by zero if its new temperature is evaluated.
			material(false, ALU_CONDUCT, ALU_HCAP, 0), //Aluminum
			material(true, AIR_CONDUCT, AIR_HCAP, AMBIENT_TEMP), //Air
			material(true, ALU_CONDUCT, ALU_HCAP, 100) //Heated Aluminum
	};

	NUM currentTemps[MAP_Z][MAP_Y][MAP_X] = {
			{
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}
			},
			{
					{0, 0, 0, 0},
					{0, 6, 5, 0},
					{0, 4, 3, 0},
					{0, 0, 0, 0}
			},
			{
					{0, 0, 0, 0},
					{0, 3, 2, 0},
					{0, 1, 0, 0},
					{0, 0, 0, 0}
			},
			{
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}
			}
	};

	NUM newTemps[MAP_Z][MAP_Y][MAP_X];

	int materials[MAP_Z][MAP_Y][MAP_X] = {
			{
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}
			},
			{
					{0, 0, 0, 0},
					{0, 1, 1, 0},
					{0, 1, 1, 0},
					{0, 0, 0, 0}
			},
			{
					{0, 0, 0, 0},
					{0, 1, 1, 0},
					{0, 1, 1, 0},
					{0, 0, 0, 0}
			},
			{
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0},
					{0, 0, 0, 0}
			}
	};


	NUM flowsX[MAP_Z][MAP_Y][MAP_X-1];
	NUM flowsY[MAP_X][MAP_Z][MAP_Y-1];
	NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1];

//	updateFlows2D(currentTemps, flowsX, flowsY, materials, matRef);
//	updateTemps2D (DELTATIME, currentTemps, newTemps, flowsX, flowsY, materials, matRef);

	updateFlows3D(currentTemps, flowsX, flowsY, flowsZ, materials, matRef);

	printFlows3D(flowsX, flowsY, flowsZ);


}
