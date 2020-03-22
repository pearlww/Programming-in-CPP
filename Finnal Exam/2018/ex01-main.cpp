#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(void){

	// Array containing Celsius
	// temperatures initialized to 100
	unsigned int n = 4;
	double *A = createAndInitArray(n,100);
	
	// Setting some values in the array
	unsigned int m = 3;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			A[i]+=i*n+j*3;
		}
	}
	printArray(A,n,"main array");

	double * B = duplicateArray(A,n);
	printArray(B,n,"copy");

	//I change B, and I print B and A
	B[0] = B[0]+3;
	B[1] = B[0]+3;
	B[2] = B[1]+3;

	printArray(B,n,"modified copy");
	printArray(A,n,"main array");

	//I deallocate B
	deallocateArray(B);

	//I convert to Fahrenheit
	double * C = toFahrenheit(A,n);
	printArray(C,n,"Fahrenheit copy");
	printArray(A,n,"main array not modified");

	//I deallocate A and C
	deallocateArray(A);
	deallocateArray(C);
	
	cout << "Completed"<<endl;
	return 0;
}