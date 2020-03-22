#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

#include <vector>
#include <string>
using namespace std;

unsigned int ** createMatrix(int n, int m);
void deallocateMatrix(unsigned int ** A, int n);
void fillWhite(unsigned int ** A, int n, int m);
void lighten(unsigned int ** A, int n, int m);
void darken(unsigned int ** A, int n, int m);
void printMatrix(unsigned int ** A, int n, int m,
			string description);

#endif /* EX01_LIBRARY_H_ */