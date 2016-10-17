/* updateTemps
 *
 * input: (cellCount, currentTemps[], newTemps[], flows[], materials[], matRef[])
 * output: bool exit code
 *
 * */

#include "updateTemps.h"
#include "energyTempConversion.h"

bool updateTemps(NUM cellCount, NUM currentTemps[], NUM newTemps[], NUM flows[], NUM materials[], material matRef[])
{
	fixpoint energy, flow;
	material *material;

	for(int i = 0; i < cellCount-1; i++) // Loop through all cells
	{
		material = &matRef[materials[i]];
		energy = temp2energy(currentTemps[i], material->heatCapacity);



		// newTemp = currentT
		//int newEnergy = currentTemps[i]
		//newTemps[i] = c2energy(currentTemps[i], ;


	}


	return true;
}
