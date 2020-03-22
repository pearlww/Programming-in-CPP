//============================================================================
// Name        : live02-test06-stack.cpp
// Description : Example of stack overflow
//============================================================================

#include <iostream>
#include <istream>
#include <string>
using namespace std;


// This is a global variable that we will use
// to record the depth of the call stack
int depth = 0 ;

// A dummy function that does nothing useful
void f(void){

    int a[10000];

    // We print the current depth
    cout << "depth " << depth << " reached in f()...\n" ;

    // We increment the depth
    depth++;

    // We call f again
    f();

}

// A f but without allocating data
void g(void){

    // This is the difference with respect to f()
    // int a[10000];

    // We print the current depth
    cout << "depth " << depth << " reached in g()...\n" ;

    // We increment the depth
    depth++;

    // We call g again
    g();

}

int main(){

    string answer;

    cout << "Do you want f() to allocate data? (yes/no): ";
    cin >> answer ;

    if (answer == "yes" ) {
        f();
    }
    else if (answer == "no"){
        g();
    }
    else {
        cout << "I will take that for a no." << endl;
        g();
    }
	system("pause");
    return 0;
}

// Ordinary compilation like
// g++ -o live02-test06-stack live02-test06-stack.cpp
// may make the program fail (segmentation fault)

// Optimized compilation like
// g++ -o live02-test06-stack -O3 live02-test06-stack.cpp
// may make the program run forever
