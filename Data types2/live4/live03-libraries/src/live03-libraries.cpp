//============================================================================
// Name        : live03-libraries.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Example on how to define and use libraries
//============================================================================

#include <iostream>
#include <string>

// Here I include the header of my libary

#include "my_sweet_library.h"
//#include "my_sweet_library.h"


// I don't need to include the implementation
// if my compiler knows how to compile and link it
//#include "my_sweet_library.cpp"

using namespace std;

int main(){

    string s;

    while(true){
        cout << "Give me a word: ";
        cin >> s;

        // I use here some functions of my sweet library
        cout <<       sweet(cool(s))  << endl;
        cout <<       cool(sweet(s))  << endl;
        cout << weird(cool(sweet(s))) << endl;
    }

    return 0;
}

