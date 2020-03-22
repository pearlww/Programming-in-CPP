#include <iostream>
#include <string>
#include "ex01-library.h"

using namespace std;

int main(void){
    
    unsigned int n = 3;
    double * A = new double[n*n];
    
    reset(A,n,7);
    display(A,n);
    
    return 0;
    
}
