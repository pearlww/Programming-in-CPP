#include <iostream>
#include <string>
#include "ex04-library.h"

using namespace std;

void f(Monoid<string> * & p){
        Monoid<string> x("x");
        Monoid<string> y("y");
        p = new Monoid<string>(x,y);
}

int main(void){
    
    Monoid<string> * p;
    f(p);
    
    p->print();
    cout << endl;
    
    return 0;
}
