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
    Monoid<string> a("Hello");
    Monoid<string> b(" ");
    Monoid<string> c("world!");
    
    Monoid<string> d(a,b);
    Monoid<string> e(d,c);
    
    cout << e.eval(concat) << endl;
    cout << (a * b * c).eval(concat) << endl;
    
    Monoid<unsigned int> u(1);
    Monoid<unsigned int> v(2);
    Monoid<unsigned int> w(3);
    
    cout << (u * v * w).eval(add) << endl;
    
    return 0;
}
