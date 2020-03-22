//============================================================================
// Name        : live01-allocation-stack-heap-solutions.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : How are vectors and arrays allocated? With solutions
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

// see
// http://www.learncpp.com/cpp-tutorial/79-the-stack-and-the-heap/

// this x will be allocated in the globals area,NOT heap or stack
int x;

int * fBADorGOOD (       // whenever f is invoked...
        int x, // a *new* variable x will be allocated in the stack
        int *y, // a new variable y will be allocated in the stack
        int &z // z already in memory, only ref to z is allocated in the stack
		){
	//BAD//

	/*
	int i=53;
	return &i;
	*/

	//GOOD//
	/*
	int * i = new int;
	*i=5;
	return i;
	*/

	//BAD//

	int a[100];
	return a;


	//GOOD//
	/*
	int * a = new int[2];
	a[0]=1;
	return a;
	*/
}

//NO
/*
vector<int>* createVector(){
	vector<int> v(10);
	return &v;
}
*/

int * f(       // whenever f is invoked...
        int x, // a *new* variable x will be allocated in the stack
        int *y, // a new variable y will be allocated in the stack
        int &z // z already in memory, only ref to z is allocated in the stack
);

int main(){

    // this x will be allocated in the heap. No, in STACK
    int x;

    x=0;
    cout << "x is " << x << endl;

    // This opens a scope, just as for, while, if, ...
    {
        // this (new!) x will be allocated in the stack
        int x;
        x=1;
        cout << "x is " << x << endl;

        // This opens another scope
        {
            // this (new!) x will be allocated in the stack
            int x;
            x=2;
            cout << "x is " << x << endl;
        } // this closes the scope, the x above will be deallocated

    } // this closes the scope, the x above will be deallocated

    cout << "x is " << x << endl;

    return 0;

}

int * f(       // whenever f is invoked...
        int x, // a *new* variable x will be allocated in the stack
        int *y, // a new variable y will be allocated in the stack
        int &z // z already in memory, only ref to z is allocated in the stack
){
    // local variables will be allocated in the stack
    // e.g. basic datatypes, arrays, etc.
    int u;
    u=5;
    int a[100];
    a[0]=1;

    // some data may be allocated in the heap
    // e.g. using "new"
    // this allocates a new integer in the heap
    y=new int;
    // or a container
   // vector<int> v(100);

    // when the function terminates...
    // all arguments (x and y) are deallocated,
    // all local variables are deallocated,
    // we cannot for instance return a pointer to some element in a
    // return &a[50];

    // but dynamically allocated objects are *not* deallocated
    // e.g. the object pointed by y, vector v;
    // we hence can return the value of y
    // or a pointer to an element in v
    return y;
    //return &*(v.begin()+50);

}
