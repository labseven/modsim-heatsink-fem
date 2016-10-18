/* updateTemps
 *
 * input: (cellCount, currentTemps[], newTemps[], flows[], materials[], matRef[])
 * output: bool exit code
 *
 * */

#include "updateTemps.h"
#define DEBUG 0

NUM newTemp(NUM currentTemp, NUM deltaTime, int inMaterial, material matRef[], NUM flow1, NUM flow2)
{
	NUM newEnergy, newTemperature, currentEnergy;
	material *thisMaterial;

	thisMaterial = &matRef[inMaterial];
	if(thisMaterial->constantTemp){
		if(DEBUG) std::cout << "constantTemp, will not change\n";
		return (thisMaterial->tempSetPoint);
	}

	currentEnergy = temp2energy(currentTemp, thisMaterial->heatCapacity);

	newEnergy = currentEnergy + ((flow1-flow2) * deltaTime); // Flows move left to right, add left one, subtract right one
	if(DEBUG) std::cout << "Update Temp: currE: " << currentEnergy << "J flow1: " << flow1 << "W flow2: " << flow2 << "W  newE: " << newEnergy << "J (dt: " << deltaTime << ") \n";

	newTemperature = energy2temp(newEnergy, thisMaterial->heatCapacity);

	if(DEBUG) std::cout << "new temp: " << newTemperature << "C\n";

	if (newTemperature < 0){
		if(DEBUG) std::cout << "Warning: new temp is < 0. (" << newTemperature << ")\n";
	}
	return newTemperature;
}

bool updateTemps(int cellCount, NUM deltaTime, NUM currentTemps[], NUM newTemps[], NUM flows[], int materials[], material matRef[])
{

	if(DEBUG) std::cout << "\nupdateTemps: \n";
	for(int i = 0; i < cellCount; i++) // Loop through all cells
	{
		newTemps[i] = newTemp(currentTemps[i], deltaTime, materials[i], matRef, flows[i-1], flows[i]);
	}


	return true;
}
