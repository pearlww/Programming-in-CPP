#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Check and correct if necessary
double * createAndInitArray(unsigned int n, double value){
	double * A = new double[n];
	for(unsigned int i = 0; i<n; i++){
		A[i] = value;
	}
	return A;
}

//Exercise 1 (b) Implement this function
double * duplicateArray(double * A, unsigned int n){
	//put your code here
	double *B = new double[n];
	for (int i = 0; i < n; i++){
		B[i] = A[i];
	}
	return B;
}

//Exercise 1 (c) Implement this function
void deallocateArray(double * A){
	//put your code here
	delete[] A;
}

//Exercise 1 (d) Implement this function
double * toFahrenheit(double * A, unsigned int n){
	//put your code here
	double *B = new double[n];
	for (int i = 0; i < n; i++){
		B[i] = A[i]*1.8+32;
	}
	return B;
}

//Do not modify
void printArray(double * A, unsigned int n, string descr){
	cout<< "Printing: " << descr << endl;
	for(unsigned int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << "\n\n";
}
