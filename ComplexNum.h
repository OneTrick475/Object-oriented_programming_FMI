#pragma once

class ComplexNum {
private:
	int x;
	int y;

public:
	

	ComplexNum();

	ComplexNum(int x, int y);

	bool isEqual(const ComplexNum& other) const;

	ComplexNum add(const ComplexNum& other) const;

	ComplexNum subtract(const ComplexNum& other) const;

	ComplexNum multiply(const ComplexNum& other) const;

	void conjugate();

	ComplexNum getConjugated() const;

	void print() const;
};
