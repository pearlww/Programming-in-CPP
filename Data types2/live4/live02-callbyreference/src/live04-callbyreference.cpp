//============================================================================
// Name        : live02-callbyreference.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Example on passing values by reference
//============================================================================

#include <iostream>
using namespace std;

// swap that does not work
void swapDummy(int px, int py){
    int z;
    z  = px;
    px = py;
    py = z;
}


struct intPair {
    int u;
    int v;
};

// swap in functional style (call-by-value)
intPair swap1(intPair input){
    intPair result;

    result.u = input.v;
    result.v = input.u;

    return result;
}

// swap in indirect call-by-reference
// i.e. call-by-reference encoded with call-by-value using pointers
void swapWithPointers(int* px, int* py){
    int z;

    z  = *px;
    *px = *py;
    *py = z;
}

// swap in call-by-reference style
void swapByReference(int & x, int & y){
    int z;

    z = x;
    x = y;
    y = z;
}

int main(void){
    int a, b;
    intPair p;

    a = 1;
    b = 2;
    cout << "Initial values" << endl;
    cout << "a,b = " << a << "," << b << endl;

    cout << "Dummy swap\n";
    swapDummy(a,b);
    cout << "a,b = " << a << "," << b << endl;

    cout << "Swapping functional style\n";
    p.u = a;
    p.v = b;
    p = swap1(p);
    a = p.u;
    b = p.v;
    cout << "a,b = " << a << "," << b << endl;

    cout << "Swapping by reference (via pointers)\n";
    swapWithPointers(&a,&b);
    cout << "a,b = " << a << "," << b << endl;

    cout << "Swapping by reference\n";
    swapByReference(a,b);
    cout << "a,b = " << a << "," << b << endl;

	system("pause");
}
