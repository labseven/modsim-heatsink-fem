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
#define REPS 10

using namespace std;

int main() {

	time_t start;
	time_t end;

	long unsigned int primes[REPS], thisPrime;

	primes[0] = 2;
	
	for (int i = 1; i < REPS; i++) {

	  thisPrime = 1;
	  for (int j = 0; j < i; j++) thisPrime = thisPrime * primes[j];
	  thisPrime++;

	  primes[i] = thisPrime;
	  cout << thisPrime <<endl;

	}


	return(0);

}
