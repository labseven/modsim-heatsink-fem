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

NUM newTemp2D(NUM currentTemp, NUM deltaTime, int inMaterial, material matRef[], NUM flowX1, NUM flowX2,NUM flowY1, NUM flowY2)
{

	NUM newEnergy, newTemperature, currentEnergy;
	material *thisMaterial;

	thisMaterial = &matRef[inMaterial];
	if(thisMaterial->constantTemp){
		if(DEBUG) std::cout << "updateTemp2D: constantTemp, will not change\n";
		return (thisMaterial->tempSetPoint);
	}

	currentEnergy = temp2energy(currentTemp, thisMaterial->heatCapacity);

	newEnergy = currentEnergy + (((flowX1-flowX2) + (flowY1-flowY2)) * deltaTime); // Flows move left to right, up to down; add left/up, subtract right/down

	if(DEBUG) std::cout << "updateTemp2D: currE: " << currentEnergy << "J flowX1: " << flowX1 << "W flowX2: " << flowX2 << "W flowY1: " << flowY1 << "W flowY2: " << flowY2 << "W  newE: " << newEnergy << "J (dt: " << deltaTime << ") ";

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

bool updateTemps2D (NUM deltaTime, NUM currentTemps[MAP_Y][MAP_X], NUM newTemps[MAP_Y][MAP_X], NUM flowsX[MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Y-1], int materials[MAP_Y][MAP_X], material matRef[])
{
	if(DEBUG) std::cout << "\nupdateTemps2D: \n";
	for(int x = 0; x < MAP_X; x++) // Loop through all cells
	{
		for(int y = 0; y < MAP_Y; y++)
		{
			newTemps[y][x] = newTemp2D(currentTemps[y][x], deltaTime, materials[y][x], matRef, flowsX[y][x-1], flowsX[y][x], flowsY[x][y-1], flowsY[x][y]); // Errors will occur here from picking wrong flowsX and flowsY values
		}
	}


	return true;

}
