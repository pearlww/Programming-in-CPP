#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(void){
    
    unsigned int n = 3;
    double * A = new double[n*n];
    
    A[0*3+0] = 1;
    A[0*3+1] = 0;
    A[0*3+2] = 0;
    A[1*3+0] = 0;
    A[1*3+1] = 0;
    A[1*3+2] = 0;
    A[2*3+0] = 0;
    A[2*3+1] = 0;
    A[2*3+2] = 0;
    
    for (int i=0; i<5; i++) {
        display(A,n);
        cout << endl;
        reduce(A,n);
    }
    
    return 0;
    
}
