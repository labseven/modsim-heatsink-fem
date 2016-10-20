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

bool clearCSV()
{
	ofstream myfile;
	myfile.open ("output.csv");
	myfile <<"\"Time\",\"x\", \"Temperature\"\n";
	myfile.close();
	return true;
}
