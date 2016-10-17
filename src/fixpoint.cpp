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


long int fixpoint::getValue() const {

	return this->value;

}

double fixpoint::toDouble() const {

	return value / multiplier;

}

fixpoint fixpoint::operator+=(double valIn) {

	this->value += valIn * multiplier;

	return *this;

}

fixpoint fixpoint::operator+=(const fixpoint &fixpointIn) {

	this->value += fixpointIn.getValue();

	return *this;

}

fixpoint fixpoint::operator++() {

	this->value += multiplier;
	return *this;

}

fixpoint operator+(fixpoint left, const fixpoint &right) {

	left += right;
	return left;

}

fixpoint fixpoint::operator-=(double valIn) {

	this->value -= valIn * multiplier;

	return *this;

}

fixpoint fixpoint::operator-=(const fixpoint &fixpointIn) {

	this->value -= fixpointIn.getValue();

	return *this;

}

fixpoint fixpoint::operator--() {

	this->value -= multiplier;
	return *this;

}

fixpoint operator-(fixpoint left, const fixpoint &right) {

	left -= right;
	return left;

}

fixpoint fixpoint::operator*= (double valIn) {

	this->value *= valIn;
	return *this;

}


fixpoint fixpoint::operator*= (const fixpoint &fixpointIn){

	this->value *= fixpointIn.toDouble();
	return *this;

}

fixpoint operator*(fixpoint left, const fixpoint &right) {

	left *= right;
	return left;

}

fixpoint fixpoint::operator/= (double valIn) {

	this->value /= valIn;
	return *this;

}


fixpoint fixpoint::operator/= (const fixpoint &fixpointIn){

	this->value /= fixpointIn.toDouble();
	return *this;

}

fixpoint operator/(fixpoint left, const fixpoint &right) {

	left /= right;
	return left;

}


