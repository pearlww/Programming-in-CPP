//============================================================================
// Name        : live03-myMatrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "myMatrix.h"
using namespace std;

int main(void){

    myMatrix m(3,2);

    cout << "Initial matrix" << endl;
    cout << "==============" << endl;
    m.display();
    cout << endl;

    cout << "Setting values..." << endl;
    cout << "=================" << endl;
    for(unsigned int i=0; i<m.numRows(); i++){
        for(unsigned int j=0; j<m.numColumns(); j++){
            m[make_pair(i,j)] = 1.0 / ( (i+1.0) * (j+2.0) );
        }
    }
    m.display();
    cout << endl;

    m.scalar_mult(0.5);
    cout << "Multiplying..." << endl;
    cout << "==============" << endl;
    m.display();
    cout << endl;

    m.transpose();
    cout << "Transposing..." << endl;
    cout << "=============" << endl;
    m.display();
    cout << endl;

}
