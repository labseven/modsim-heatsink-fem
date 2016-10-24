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
