/* updateTemps
 *
 * input: (cellCount, currentTemps[], newTemps[], flows[], materials[], matRef[])
 * output: bool exit code
 *
 * */

#include "updateTemps.h"
#include "energyTempConversion.h"

NUM newTemp(NUM currentTemp, NUM deltaTime, int inMaterial, material matRef[], NUM flow)
{
	NUM newEnergy, newTemperature, currentEnergy;
	material thisMaterial;

	thisMaterial = &matRef[inMaterial];
	currentEnergy = temp2energy(currentTemp, thisMaterial->heatCapacity);


	newEnergy = energy + (flow * deltaTime);

	newTemperature = energy2temp(newEnergy, thisMaterial->heatCapacity);


	if (newTemprature < 0){
		std::cout << "Warning: new temp is <0. (" << newTemprature << ")\n";
	}
	return newTemperature;
}

bool updateTemps(NUM cellCount, NUM deltaTime, NUM currentTemps[], NUM newTemps[], NUM flows[], int materials[], material matRef[])
{
	NUM energy, flow;
	material *thisMaterial;

	for(int i = 0; i < cellCount-1; i++) // Loop through all cells
	{
		newTemps[i] = newTemp(currentTemps[i], deltaTime, materials[i], matRef, flows[i]);
	}


	return true;
}
