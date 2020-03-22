//============================================================================
// Name        : live01-types.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Simple example on types, mixed data types, and casting
//============================================================================

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main(void){

    // The type of an expression can be
    // obtained with typeid(expression).name()
    // For example...
    cout << "The type of 3.14 is " << (typeid(3.14)).name() << endl;
    cout << "The type of 3.14f is " << (typeid(3.14f)).name() << endl;
    cout << "The type of 3.14l is " << (typeid(3.14l)).name() << endl;
    cout << "The type of 9/(float)6 is " << (typeid(9/(float)6)).name() << endl;
    cout << "The type of 9.0/6 is " << (typeid(9.0/6)).name() << endl;
    cout << "The type of 9/6.0 is " << (typeid(9/6.0)).name() << endl;
    cout << "The type of 9/(int)6.0 is " << (typeid(9/(int)6.0)).name() << endl;
    cout << "The type of (float)(9/6) is " << (typeid((float)(9/6))).name() << endl;
	system("pause");
    return 0;

}
