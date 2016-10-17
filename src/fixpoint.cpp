/*
 * fixpoint.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: neophile
 */

#include "fixpoint.h"

fixpoint::fixpoint(double valIn) {

	value = valIn * multiplier;

}

fixpoint::fixpoint(const fixpoint &fixpointIn) {

	value = fixpointIn.value;

}



fixpoint::~fixpoint() {

}


long int fixpoint::getValue() {

	return this->value;

}

double fixpoint::toDouble() {

	return value / multiplier;

}

fixpoint fixpoint::operator+=(double valIn) {

	this->value += valIn * multiplier;

	return *this;

}

fixpoint fixpoint::operator+=(fixpoint &fixpointIn) {

	this->value += fixpointIn.getValue();

	return *this;

}

fixpoint operator+(fixpoint &left, fixpoint &right) {

	left += right;
	return left;

}



