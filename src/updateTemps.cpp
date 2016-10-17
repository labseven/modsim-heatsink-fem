/* updateTemps
 *
 * input: (cellCount, currentTemps[], newTemps[], flows[], materials[], matRef[])
 * output: bool exit code
 *
 * */

#include "updateTemps.h"

NUM newTemp(NUM currentTemp, NUM deltaTime, int inMaterial, material matRef[], NUM flow)
{
	NUM newEnergy, newTemperature, currentEnergy;
	material *thisMaterial;

	thisMaterial = &matRef[inMaterial];
	currentEnergy = temp2energy(currentTemp, thisMaterial->heatCapacity);


	newEnergy = currentEnergy + (flow * deltaTime);

	newTemperature = energy2temp(newEnergy, thisMaterial->heatCapacity);


	if (newTemperature < 0){
		std::cout << "Warning: new temp is < 0. (" << newTemperature << ")\n";
	}
	return newTemperature;
}

bool updateTemps(int cellCount, NUM deltaTime, NUM currentTemps[], NUM newTemps[], NUM flows[], int materials[], material matRef[])
{

	for(int i = 0; i < cellCount-1; i++) // Loop through all cells
	{
		newTemps[i] = newTemp(currentTemps[i], deltaTime, materials[i], matRef, flows[i]);
	}


	return true;
}
