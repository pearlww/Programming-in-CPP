#include <iostream>
#include <string>
#include "ex04-library.h"

using namespace std;

string concat(string u, string v){
    return u + v;
}

unsigned int add(unsigned int u, unsigned int v){
    return u + v;
}

int main(void){
    
    Monoid<string> a("Hello World!");

    a.print();
    cout << endl;
    
    return 0;
}
