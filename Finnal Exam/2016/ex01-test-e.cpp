#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(void){
    
    unsigned int n = 3;
    double * A = new double[n*n];
    
    A[0*3+0] = 1;
    A[0*3+1] = 2;
    A[0*3+2] = 3;
    A[1*3+0] = 4;
    A[1*3+1] = 5;
    A[1*3+2] = 6;
    A[2*3+0] = 7;
    A[2*3+1] = 8;
    A[2*3+2] = 9;
 
    vector<double> v;
    v = sumCols(A,n);
    print(v);
    
    return 0;
    
}
