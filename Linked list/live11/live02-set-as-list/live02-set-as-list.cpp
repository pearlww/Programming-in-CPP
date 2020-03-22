//============================================================================
// Name        : live02-set-as-list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Implementing a set using a linked list
//============================================================================


#include <iostream>
#include "mySetAsLinkedList.h"

using namespace std;

int main(){
    Set<int> set1, set2;


    cout << "Inserting some numbers in S1..." << endl;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.print();

    cout << "Inserting some numbers in S2..." << endl;
    set2.insert(3);
    set2.insert(2);
    set2.insert(1);
    set2.print();

    cout << "Are S1 and S2 equal?... ";
    cout << ((set1 == set2) ? "yes!" : "no!") << endl;

    set2.insert(1);

    cout << "Are S1 and S2 equal?... ";
    cout << ((set1 == set2) ? "yes!" : "no!") << endl;


    set2.insert(4);

    cout << "Are S1 and S2 equal?... ";
    cout << ((set1 == set2) ? "yes!" : "no!") << endl;

    return 0;
}
