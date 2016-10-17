/*
 * main.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: neophile
 */

#include "main.h"

using namespace std;

int main() {


	material matRef[] = {
			material(true, 0, 0, 0), //Magic wall.  Yes, this will cause division by zero if its new temperature is evaluated.
			material(false, ALU_CONDUCT, ALU_HCAP, 0), //Aluminum
			material(true, AIR_CONDUCT, AIR_HCAP, AMBIENT_TEMP) //Air
	};

	NUM temps[] = {0,0,1,0};

	cout << "Original temps: ";
	for (int i = 0; i<4; i++) {
		cout << temps[i] << "C, ";
	}
	cout << "\n";

	NUM newTemps[] = {0,0,0,0};
	int materials[] = {0, 1, 1, 0};
	NUM flows[] = {-1, -1, -1};

	if (updateFlows (4, temps, flows, materials, matRef)) {
	} else cout <<"updateFlows failed.\n";

	if (updateTemps(4, DELTATIME, temps, newTemps, flows, materials, matRef)){
		cout << "Temperatures: ";
		for (int i = 0; i<4; i++) {
			cout << newTemps[i] << "C, ";
		}
		cout << "\n";
	} else cout << "updateTemps failed.\n";
}




