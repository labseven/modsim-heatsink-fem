/*
 * multithreadingTest.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: neophile
 */

#include <thread>
#include <iostream>
#include <time.h>

#define THREADNUM 1

using namespace std;

int main() {

	time_t start;
	time_t end;

	long long unsigned int factorial = 1;

	for (int j = 1; j < 80; j++) {
		factorial = 1;
		for (int i = 1; i < j; i++) factorial = factorial * i;
		cout << factorial;
	}

	return(0);

}
