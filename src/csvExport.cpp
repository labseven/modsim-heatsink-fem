#include "csvExport.h"
using namespace std;
#define DEBUG 0

bool csvExport(int cellCount, NUM currentTemps[], NUM currentTime)
{
	ofstream myfile;
	myfile.open ("output.csv", ios::app);

	for(int i = 0; i < cellCount; i++)
	{
	myfile << currentTime << "," << i << "," << currentTemps[i] << "\n";
	}
	myfile.close();

	return true;
}

bool csvExport2D(NUM currentTemps[MAP_Y][MAP_X], NUM currentTime)
{
	ofstream myfile;
	myfile.open ("output2D.csv", ios::app);

	for(int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{
			myfile << currentTime << "," << y << "," << x << "," << currentTemps[y][x] << "\n";
		}
	}
	myfile.close();


	return true;
}

bool clearCSV()
{
	ofstream myfile;
	myfile.open ("output.csv");
	myfile <<"\"Time\",\"x\", \"Temperature\"\n";
	myfile.close();
	return true;
}

bool clearCSV2D()
{
	ofstream myfile;
	myfile.open ("output2D.csv");
	myfile <<"\"Time\",\"y\", ,\"x\", \"Temperature\"\n";
	myfile.close();
	return true;
}

bool clearPython2D()
{
	ofstream myfile;
	myfile.open ("outputPython.csv");
	myfile << MAP_X << "," << MAP_Y <<  "\n";
	myfile.close();
	return true;
}

bool exportPython2D(NUM currentTemps[MAP_Y][MAP_X], NUM currentTime)
{
	ofstream myfile;
	myfile.open ("outputPython.csv", ios::app);

	myfile << currentTime << "\n";

	for(int y = 0; y < MAP_Y; y++)
	{
		for (int x = 0; x < MAP_X; x++)
		{
			myfile << currentTemps[y][x] << ",";
		}
		myfile << "\n";
	}
	myfile.close();


	return true;
}

bool clearPython3D(int edgeRemove = 0)
{
	ofstream myfile;
	myfile.open ("outputPython.csv");
	myfile << MAP_X-(edgeRemove*2) << "," << MAP_Y-(edgeRemove*2) << "," << MAP_Z-(edgeRemove*2) << "\n";
	myfile.close();
	return true;
}

bool exportPython3D(NUM currentTemps[MAP_Z][MAP_Y][MAP_X], NUM currentTime, int edgeRemove = 0)
{
	ofstream myfile;
	myfile.open ("outputPython.csv", ios::app);

	myfile << currentTime << "\n";

	for(int z = edgeRemove; z < MAP_Z-edgeRemove; z++)
	{
		for(int y = edgeRemove; y < MAP_Y-edgeRemove; y++)
		{
			for (int x = edgeRemove; x < MAP_X-edgeRemove; x++)
			{
				myfile << currentTemps[z][y][x] << ",";
			}
			myfile << "\n";
		}
	}
	myfile.close();


	return true;
}
bool clearExportPower()
{
	ofstream myfile;
	myfile.open ("outputEnergy.csv");
	myfile.close();
	return true;
}
bool exportPower(NUM currentTime, NUM energy, NUM deltaTime, NUM airspeedDivisor)
{
	ofstream myfile;
	myfile.open ("outputEnergy.csv", ios::app);
	myfile << currentTime << "," << energy*1./(deltaTime * airspeedDivisor) << "\n";
	myfile.close();
	return true;
}
