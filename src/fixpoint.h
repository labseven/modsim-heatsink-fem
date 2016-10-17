/*
 * fixpoint.h
 *
 *  Created on: Oct 16, 2016
 *      Author: neophile
 */

#ifndef FIXPOINT_H_
#define FIXPOINT_H_

class fixpoint {
public:
	fixpoint(long int valIn);
	virtual ~fixpoint();
	long int getVal();
	fixpoint operator+ (fixpoint &right);

private:
	long int value;
};

#endif /* FIXPOINT_H_ */
