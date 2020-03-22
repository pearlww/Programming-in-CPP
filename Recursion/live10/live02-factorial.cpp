//============================================================================
// Name        : live02-factorial.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Factorial, recursively
//============================================================================

#include<iostream>
using namespace std;

// Recursive factorial (standard)
double fact(double n){
	if (n==0) {
		return 1;
	} else {
		return n*fact(n-1);
	}
}

// Recursive factorial (tail recursive)
double fact2(double n, double r=1){
	if (n==0) {
		return r;
	}
	return fact2(n-1,n*r);
}

double factPRINT(double n){

	if (n == 0) {
		cout << "fact(" << n << ") = 1" << endl ;
		return 1;
	} else {
		cout << "fact(" << n << ") = " << n << " * fact(" << n-1 << ") " << endl;
		return n*factPRINT(n-1);
	}
}


int main(){

	double n;

	// Try with with big numbers, e.g. 1000000
	// Compare compilation with and without optimization (-O3)
	cout << "Give me a non-negative double: " ;
	cin >> n;
	cout << "Computing fact(" << n << ") ..." << fact(n) << endl;
	cout << "Computing fact2(" << n << ") ..." << fact2(n) << endl;

	cout << "Computing factPRINT(" << n << ") ..." << endl;
	factPRINT(n);

	return 0;
}
