#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(void){
    
    // I am building my initial matrix here
    unsigned int n = 3;
    double * * A = new double *[n];
    for(unsigned int i = 0; i<n; i++){
        A[i] = new double[n];
    }
    
    // Setting all values to 0
    reset(A,n,0);
    // Setting some values in the matrix
    A[0][1] = 1;
    A[1][0] = 2;
    A[1][2] = 3;
    A[2][1] = 4;
    display(A,n);
    cout << endl;

    // Summing up rows and values
    vector<double> v;
    v = sumRows(A,n);
    print(v);
    v = sumCols(A,n);
    print(v);
    cout << endl;
    
    // Reducing the matrix
    reduce(A,n);
    display(A,n);
    
    for(unsigned int i = 0; i<n; i++){
        delete [] A[i];
    }
    delete [] A;
     
	system("pause");
    return 0;
    
}
