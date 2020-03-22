#ifndef MYFRACTIONS_H_
#define MYFRACTIONS_H_

using namespace std;

enum opration{
	add,mult,divide};

int str2int(string s);


class fraction {
private:
	// Internal representation of a fraction as two integers
	int numerator;
	int denominator;
public:
	// Class constructor
	fraction(int n, int d);
	// Methods to update the fraction
	void add(fraction f);
	void mult(fraction f);
	void div(fraction f);
	// Display method
	void display(void);
	void reduction(void);
};

#endif