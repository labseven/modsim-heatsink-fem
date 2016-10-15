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

	NUM temps[] = {c2units(0), c2units(0), c2units(1), c2units(0)};
	NUM materials[] = {0, 1, 1, 0};
	NUM flows[] = {-1, -1, -1};

	if (updateFlows (4, temps, flows, materials, matRef)) {
		for (int i = 0; i < 3; i++) {
			cout << units2w(flows[i]) <<", ";
		}

	} else cout <<"updateFlows failed.\n";

}




