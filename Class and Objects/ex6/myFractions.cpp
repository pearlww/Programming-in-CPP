#include <iostream>
#include "myFractions.h"

using namespace std;


fraction::fraction(int n, int d){
	numerator = n;
	denominator = d;
	return;
}

void fraction::add(fraction f){
	
	//you must calculate numerator first
	numerator = (numerator*f.denominator) + (f.numerator*denominator);
	denominator = denominator * f.denominator;

	return;
}

void fraction::mult(fraction f){

	denominator = denominator * f.denominator;
	numerator = numerator * f.numerator;

	return;
}

void fraction::div(fraction f){
	denominator = denominator * f.numerator;
	numerator = numerator * f.denominator;

	return;
}
void fraction::display(void){
	cout << numerator << " " << "/" << " " << denominator << endl;
}


void fraction::reduction(void){

	for (int i = 2; i < denominator*numerator; i++){
		if (denominator%i == 0 && numerator%i == 0){
			denominator /= i;
			numerator /= i;
		}
	}
}

int str2int(string op){
	if (op == "+") return add;
	if (op == "*") return mult;
	if (op == "div") return divide;
}