//============================================================================
// Name        : ex01_main.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Exercise 1 - Graphics Editor
//============================================================================

#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(){

	// I am building a matrix representing a picture
	unsigned int n = 4;
	unsigned int m = 4;
	int **A = createMatrix(n,m);

	// Setting all values to 0
	initMatrix(A,n,m);
	// Setting some values in the matrix
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			A[i][j]=i*n+j;
		}
	}
	A[1][0]=126;
	A[1][1]=127;
	A[1][2]=128;
	printMatrix(A,n,m,"main matrix");
	cout << endl;

	int **B = duplicateMatrix(A,n,m);
	printMatrix(B,n,m,"copy");

	//I change B, and I print B and A
	for(int j=0;j<m;j++){
		B[0][j]=B[0][j]+3;
	}

	printMatrix(B,n,m,"modified copy");
	printMatrix(A,n,m,"main matrix");

	//I deallocate B
	deallocateMatrix(B,n);

	int ** C = makeBitonal(A,n,m,127);
	printMatrix(C,n,m,"bi-tonal copy");

	deallocateMatrix(A,n);
	deallocateMatrix(C,n);

	system("pause");
	return 0;
}