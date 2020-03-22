#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(void){
    
    unsigned int n = 2;
    double * A = new double[n*n];
    
    A[0*2+0] = 1;
    A[0*2+1] = 2;
    A[1*2+0] = 3;
    A[1*2+1] = 4;
    display(A,n);
    
    return 0;
    
}
