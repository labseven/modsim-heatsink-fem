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

int main() {

	material matRef[] = {
			material(true, 0, 0, 0), //Magic wall.  Yes, this will cause division by zero if its new temperature is evaluated.
			material(false, ALU_CONDUCT, ALU_HCAP, 0), //Aluminum
			material(true, AIR_CONDUCT, AIR_HCAP, AMBIENT_TEMP), //Air
			material(true, ALU_CONDUCT, ALU_HCAP, 100) //Heated Aluminum
	};

	// Initial temp map
	NUM temps[MAP_Y][MAP_X] = {
			{0, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
	};

	int materials[MAP_Y][MAP_X] = {
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
	};



	NUM flowsX[MAP_Y][MAP_X-1] = {
			{0, 0, 0},
			{0, 1, 1},
			{0, 1, 1}
	};

	NUM flowsY[MAP_X][MAP_Y-1] = {
			{0,0},
			{1,1},
			{0,0},
			{0,0}
	};


	updateFlows2D(temps, flowsX, flowsY, materials, matRef);


	cout << "Horizontal:";
	for (int i = 0; i < MAP_Y; i++) {

		printFlows(MAP_X-1, flowsX[i]);

	}

	cout << "\nVertical:";
	for (int i = 0; i < MAP_Y; i++) {

		printFlows(MAP_Y-1, flowsY[i]);

	}

}
