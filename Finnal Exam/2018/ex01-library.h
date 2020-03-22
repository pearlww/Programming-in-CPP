#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

#include <vector>
#include <string>
using namespace std;

double * createAndInitArray(unsigned int n, double value);
double * duplicateArray(double * A, unsigned int n);
void deallocateArray(double * A);
double * toFahrenheit(double * A, unsigned int n);			
void printArray(double * A, unsigned int n, string descr);

#endif /* EX01_LIBRARY_H_ */