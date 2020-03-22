//============================================================================
// Name        : live01-pointers.cpp
// Description : Example on pointers, referencing and dereferencing
//============================================================================

#include <iostream>
#include <climits>
using namespace std;


int main(){

    cout << "A memory address in this computer uses ";
    cout << 8 * sizeof( nullptr ) << " bits" << endl;
    cout << endl;

    cout << "An int in this computer uses ";
    cout << 8 * sizeof( int ) << " bits" << endl;
    cout << endl;

    cout << "A float in this computer uses ";
    cout << 8 * sizeof( float ) << " bits" << endl;
    cout << endl;

    cout << "A double in this computer uses ";
    cout << 8 * sizeof( double ) << " bits" << endl;
    cout << endl;

    cout << "A long double in this computer uses ";
    cout << 8 * sizeof( long double ) << " bits" << endl;
    cout << endl;


    int x,y;
    x=1;
    y=2;

    cout << "Variable x is residing in address ";
    cout << (long)&x << endl;
    cout << "Variable y is residing in address ";
    cout << (long)&y << endl;
    cout << endl;

    int *p1, *p2;
    p1=&x;
    p2=&y;

    cout << "The value of p1 (the address pointed by p1) is: ";
    cout << (long)p1 << endl;
    cout << "The value pointed by p1 is: ";
    cout << *p1 << endl;
    cout << "The value of p2 (the address pointed by p2) is: ";
    cout << (long)p2 << endl;
    cout << "The value pointed by p2 is: ";
    cout << *p2 << endl;
    cout << endl;

    x=3;
    y=4;


    cout << "The value of p1 (the address pointed by p1) is: ";
    cout << (long)p1 << endl;
    cout << "The value pointed by p1 is: ";
    cout << *p1 << endl;
    cout << "The value of p2 (the address pointed by p2) is: ";
    cout << (long)p2 << endl;
    cout << "The value pointed by p2 is: ";
    cout << *p2 << endl;
    cout << endl;

    *p1 = 5;
    cout << "The value of x is: ";
    cout << x << endl;
    cout << endl;


    int u;

    u = 23;
    cout << "The value of variable u is ";
    cout << u << endl;
    cout << "The value of variable u is ";
    cout << *&u << endl;
    cout << "The value of variable u is ";
    cout << *&*&u << endl;
    //...
    cout << endl;

//    cout << "Variable u is residing in address ";
//    cout << (long)&u << endl;
//    cout << "Variable u is residing in address ";
//    cout << (long)&*&u << endl;
//    cout << "Variable u is residing in address ";
//    cout << (long)&*&*&u << endl;
//    //...
//    cout << endl;


    int a[] = { 3, 1, 2};
    cout << "Minimum integer is: " << INT_MIN << endl;
    cout << "Maximum integer is: " << INT_MAX << endl;
    //-2^31,+2^31 - 32 bits
    cout << "The value   of a    is " << (long)a << endl;
    cout << "The address of a[0] is " << (long)&(a[0]) << endl;
    cout << "The address of a[1] is " << (long)&(a[1]) << endl;

    cout << "The value stored in the address pointed by a is " << *a << endl;
    cout << "The value stored in a[0] is " << *a << endl;
//    cout << "The address of a[0] is " << (long)&(a[0]) << endl;


    cout << "The value of a[2] is " << a[2] << endl;
    cout << "The value of *(a+2) is " << *(a+2) << endl;






	system("pause");
    return 0;

}
