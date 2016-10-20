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

int main() {


	material matRef[] = {
			material(true, 0, 0, 0), //Magic wall.  Yes, this will cause division by zero if its new temperature is evaluated.
			material(false, ALU_CONDUCT, ALU_HCAP, 0), //Aluminum
			material(true, AIR_CONDUCT, AIR_HCAP, AMBIENT_TEMP), //Air
			material(true, ALU_CONDUCT, ALU_HCAP, 100) //Heated Aluminum
	};

	// Setup Parameters
	const int cellCount = 6;
	NUM currentTemps[] = 		{0, 0, 25, 25, 0, 0};
	int materials[] = 			{0, 3, 1,  1,  2, 0};
	const int loopTimes = 100;
	NUM currentTime = 0;

	NUM newTemps[cellCount];
	NUM flows[cellCount - 1];

	// need to initalize currentTemps array for constTemp cells (first updateFlows is wonky)
	clearCSV();

	for (int loopCounter = 0; loopCounter < loopTimes; loopCounter ++)
	{
		csvExport(cellCount, currentTemps, currentTime);

		if (updateFlows (cellCount, currentTemps, flows, materials, matRef)) {
		} else cout <<"updateFlows failed.\n";

		if (updateTemps(cellCount, DELTATIME, currentTemps, newTemps, flows, materials, matRef)){
		} else cout << "updateTemps failed.\n";


		currentTime += DELTATIME;

		// Swap newTemp into currentTemp
		memcpy(currentTemps, newTemps, sizeof(NUM)*cellCount);


		if (DEBUG) printTemps(cellCount, currentTemps);
	}
	printTemps(cellCount, currentTemps);
}
