//============================================================================
// Name        : live02-myvector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "myVector.h"

using namespace std;

int main(void){

    // we declare a myvector a
    myVector a;

    cout << "The initial size is: " <<  a.size() << endl;

    // we insert some numbers with push_back
    for(unsigned int i=0; i<10; i++){
        a.push_back(i);
    }
    cout << "After the insertions the size is: " <<  a.size() << endl;

    cout <<"[] "<< a[9] << "\n";
    cout <<"at "<< a.at(9) << "\n";

    cout << "We access elements in array-style or using 'at': " << endl;
    for(unsigned int i=0; i<a.size(); i++){
    		cout << i << " " << a.at(i) << "\n";
    }
    cout << endl;

	//error
	//cout << a.at(20) << endl;
	//cout << a[20] <<endl;


    // we open a new scope
    {
        myVector b;
        // we set b to be equal to a
		//b. = (a);
        b = a;
		

        cout << "We 'copied' the vector: " << endl;
        for(unsigned int i=0; i<b.size(); i++){
            cout << b[i] << " ";
        }
        cout << endl;

        cout << "We access and manipulate some elements in array-style." << endl;
        for(unsigned int i=2; i<a.size(); i++){
        		b[i] = b[i-1] + b[i-2];
        }
        cout << "The vector b became: " << endl;
        for(unsigned int i=0; i<b.size(); i++){
        		cout << b[i] << " ";
        }
        cout << endl;
    }
    // here b is de-allocated since it scope has finished

    cout << "The vector a became: " << endl;
    for(unsigned int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;

	//if we don't overload "=",
	// a will also changed because we use "new" to make vector,so b will take a's place
	// a is strange because b(which take a's place) is already de-allocated

	system("pause");
}
