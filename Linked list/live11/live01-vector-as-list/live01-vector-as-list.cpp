//============================================================================
// Name        : live01-myVector-as-list.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Implementing a myVector using a linked list
//============================================================================

#include <iostream>
#include "myVectorAsLinkedList.h"

//using namespace std;



int main(void){

    // we declare a myVector a
    myVector a;

    // we insert some numbers with push_back
    for(unsigned int i=0; i<10; i++){
        a.push_back(i);
    }

    std::cout << "Vector after initialization: (size " << a.size() <<" )" << std::endl;
    for(unsigned int i=0; i<a.size(); i++){
    	std::cout << a.at(i) << " ";
    }
    std::cout << std::endl;


    // we access and manipulate some elements in array-style
    for(unsigned int i=2; i<a.size(); i++){
        a[i] = a[i-1] + a[i-2];
    }

    // we access some elements usint at()
    std::cout << "Vector after manipulation: " << std::endl;
    for(unsigned int i=0; i<a.size(); i++){
    		std::cout << a.at(i) << " ";
    }
    std::cout << std::endl;

    myVector b;
    // we set b to be equal to a
    b = a;

    a[0]=100;

    std::cout << "Copy of the myVector: (size " << b.size() <<" )" << std::endl;
    for(unsigned int i=0; i<b.size(); i++){
    		std::cout << b.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;

}
