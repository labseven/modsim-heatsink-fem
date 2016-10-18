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
			material(true, 0, 0, 0), //Magic wall.  Yes, this will cause division by zero if its new temperature is evaluated.
			material(false, ALU_CONDUCT, ALU_HCAP, 0), //Aluminum
			material(true, AIR_CONDUCT, AIR_HCAP, AMBIENT_TEMP) //Air
	};

	// Setup Parameters
	NUM temps[] = {0,0,2,0};
	int materials[] = {0, 1, 1, 0};
	const int loopTimes = 10;


	NUM newTemps[] = {0,0,0,0};
	NUM flows[] = {-1, -1, -1};




	if (updateFlows (4, temps, flows, materials, matRef)) {
	} else cout <<"updateFlows failed.\n";

	if (updateTemps(4, DELTATIME, temps, newTemps, flows, materials, matRef)){
	} else cout << "updateTemps failed.\n";



	if(DEBUG){
		cout << "\nNew temps: ";

		for (int i = 0; i<4; i++) {
			cout << newTemps[i] << "C, ";
		}
		cout << "\n\n";
	}
}




