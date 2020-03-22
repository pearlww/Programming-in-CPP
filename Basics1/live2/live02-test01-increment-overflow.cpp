//============================================================================
// Name        : test01-increment-overflow.cpp
// Description : Examples illustrating arithmetic overflows
//============================================================================

#include <iostream>
#include <climits>
// This library defines some limits for numerical datatypes
// like MAX_INT, MIN_INT, etc.
// see http://www.cplusplus.com/reference/climits/

using namespace std;

// A simple function called "increment"
// that takes an int as input
// and returns an int as output
int increment(int x){
    return x + 1;
}

// similar function
int decrement(int x){
    return x - 1;
}

// similar as increment, but checks overflows
int increment_safe(int x){
    // we test if the result will overflow
    if ( (double)x + 1.0 > (double)INT_MAX ) {
        // and print a message if that is the case
        cout << endl << "Oops!!! You overflowed while trying to increment." << endl;
        // of course, priting a warning is not the best way
        // to raise a warning/error
    }
    return x + 1;
}

int main()
{
    // We declare here 3 variables of type int
    // and initialise their values
    int x = INT_MAX;
    int y = INT_MIN;
    int z = 0;

    cout << "Hello, world!" << endl;
    cout << "Give me a number please: ";
    cin >> z ;

    cout << "Incrementing " << z << " yields... " ;
    // Here you can see how function "increment" is used
    cout << increment(z) << endl ;
    cout << "Decrementing " << z << " yields... " ;
    cout << decrement(z) << endl ;

    cout <<endl;
    cout << "Hey, btw... " << endl ;

    cout <<endl;
    cout << "Incrementing " << x << " yields... " ;
    cout << increment_safe(x) << endl ;

    cout <<endl;
    cout << "Decrementing " << y << " yields... " ;
    cout << decrement(y) << endl ;

	system("pause");
    return 0;

}

