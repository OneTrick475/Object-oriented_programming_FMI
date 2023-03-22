#include <iostream>
#include "ComplexNum.h"

ComplexNum::ComplexNum() {
	this->x = 0;
	this->y = 0;
}

ComplexNum::ComplexNum(int x, int y) {
	this->x = x;
	this->y = y;
}

bool ComplexNum::isEqual(const ComplexNum& other) const {
	return x == other.x && y == other.y;
}

ComplexNum ComplexNum::add(const ComplexNum& other) const {
	return ComplexNum(x + other.x, y + other.y);
}

ComplexNum ComplexNum::subtract(const ComplexNum& other) const {
	return ComplexNum(x - other.x, y - other.y);
}

ComplexNum ComplexNum::multiply(const ComplexNum& other) const {
	return ComplexNum(x*other.x - y*other.y, x*other.y + y*other.x);
}

void ComplexNum::conjugate() {
	y *= -1;
}

ComplexNum ComplexNum::getConjugated() const {
	return ComplexNum(x, y * - 1);
}

void ComplexNum::print() const {
	std::cout << x << " + i" << y;
}


