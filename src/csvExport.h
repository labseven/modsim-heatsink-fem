/*
 * csvExport.h
 *
 *  Created on: Oct 18, 2016
 *      Author: kevin
 */

#ifndef CSVEXPORT_H_
#define CSVEXPORT_H_

#include "main.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

bool csvExport(int cellCount, NUM currentTemps[], NUM currentTime);
bool clearCSV();


bool csvExport2D(NUM currentTemps[MAP_Y][MAP_X], NUM currentTime);
bool clearCSV2D();

bool exportPython2D(NUM currentTemps[MAP_Y][MAP_X], NUM currentTime);
bool clearPython2D();

bool exportPython3D(NUM currentTemps[MAP_Z][MAP_Y][MAP_X], NUM currentTime, int edgeRemove);
bool clearPython3D(int edgeRemove);

#endif /* CSVEXPORT_H_ */
