/*
 * fixpoint.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: neophile
 */

#include "fixpoint.h"

fixpoint::fixpoint(long int valIn) {

	value = valIn;

}

fixpoint::~fixpoint() {

}

long int fixpoint::getVal() {

	return value;

}

fixpoint fixpoint::operator+(fixpoint &right) {

	return fixpoint(this->getVal() + right.getVal());

}
