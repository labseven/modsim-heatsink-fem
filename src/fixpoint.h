/*
 * fixpoint.h
 *
 *  Created on: Oct 16, 2016
 *      Author: neophile
 */

#ifndef FIXPOINT_H_
#define FIXPOINT_H_

#include "main.h"

class fixpoint {
public:
	fixpoint(double valIn);
	fixpoint(fixpoint &fixpointIn);
	virtual ~fixpoint();
	double toDouble();
	long int getValue(); //Get the value, including the multiplier.
	fixpoint operator+= (double valIn);
	fixpoint operator+= (fixpoint &fixpointIn);
	fixpoint operator-= (double valIn);
	fixpoint operator+ (fixpoint &right);
	fixpoint operator- (fixpoint &right);

private:
	long int value;
	static const long int multiplier = pow(2, 16);
};

#endif /* FIXPOINT_H_ */
