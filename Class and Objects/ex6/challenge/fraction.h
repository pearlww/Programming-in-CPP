#pragma once
class fraction
{
private:
	int numenator;
	int denominator;
public:
	fraction(int n, int d);
	int findGCD(int num, int den);
	void add(fraction f);
	void sub(fraction f);
	void mult(fraction f);
	void div(fraction f);
	void display (void);

	int pow(int num, int exp);
	int* findPrime(int num);
	void challengeAdd(fraction f);
	void challengeSub(fraction f);
	void challengeMult(fraction f);
	void challengeDiv(fraction f);
	~fraction();
};

