/*
 * print.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: neophile
 */

#include "print.h"
#define DEBUG 0

using namespace std;

bool printTemps(int cellCount, NUM temps[])
{
	std::cout << "Temperatures: ";
	for (int i = 0; i < cellCount; i++)
	{
		std::cout << temps[i] << "C ";
	}

	std::cout << "\n";
	return true;
}

bool printFlows(int cellCount, NUM flows[])
{
	std::cout << "Flows: ";
	for (int i = 0; i < cellCount; i++)
	{
		std::cout << flows[i] << "W ";
	}

	std::cout << "\n";
	return true;
}

bool printFlows3D(NUM flowsX[MAP_Z][MAP_Y][MAP_X-1], NUM flowsY[MAP_X][MAP_Z][MAP_Y-1], NUM flowsZ[MAP_Y][MAP_X][MAP_Z-1]) {

	cout <<"Flows:" <<endl << "X:" <<endl;

	for (int z = 0; z < MAP_Z; z++) { //First, the X axis flows
		for (int y = 0; y < MAP_Y; y++) {
			for (int x = 0; x < MAP_X-1; x++) {
				cout <<flowsX[z][y][x] <<", ";
			} //End x
			cout <<endl;
		} //End y
		cout <<endl <<endl;
	}//End z

	cout <<endl <<"Y:" <<endl;

	for (int x = 0; x < MAP_X; x++) { //First, the X axis flows
		for (int z = 0; z < MAP_Z; z++) {
			for (int y = 0; y < MAP_Y-1; y++) {
				cout <<flowsY[x][z][y] <<", ";
			} //End y
			cout <<endl;
		} //End z
		cout <<endl <<endl;
	}//End x

	cout <<endl <<"Z:" <<endl;

		for (int y = 0; y < MAP_Y; y++) { //First, the X axis flows
			for (int x = 0; x < MAP_X; x++) {
				for (int z = 0; z < MAP_Z-1; z++) {
					cout <<flowsZ[y][x][z] <<", ";
				} //End z
				cout <<endl;
			} //End x
			cout <<endl <<endl;
		}//End y

		return true;


} //end function


bool printTemps3D(NUM temps[MAP_Z][MAP_Y][MAP_X]) {

	cout <<"Temperatures:" <<endl;

	if (DEBUG){
		for (int z = 0; z < MAP_Z; z++) { //First, the X axis flows
			for (int y = 0; y < MAP_Y; y++) {
				for (int x = 0; x < MAP_X; x++) {
					cout <<temps[z][y][x] <<", ";
				} //End x
				cout <<endl;
			} //End y
			cout <<endl <<endl;
		}//End z
	}
	else{
		for (int z = 1; z < MAP_Z-1; z++) { //First, the X axis flows
			for (int y = 1; y < MAP_Y-1; y++) {
				for (int x = 1; x < MAP_X-1; x++) {
					cout <<temps[z][y][x] <<", ";
				} //End x
				cout <<endl;
			} //End y
			cout <<endl <<endl;
		}//End z
	}

	return true;

}
