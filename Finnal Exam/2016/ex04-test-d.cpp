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
    Monoid<string> h("Hello");
    Monoid<string> b(" ");
    Monoid<string> o("world");
    Monoid<string> a("and");
    Monoid<string> e("everybody");
    Monoid<string> f("else!");
    
    (h * b * o * b * a * b * e * b * f).print();
    cout << endl;
    
    Monoid<unsigned int> u(1);
    Monoid<unsigned int> v(2);
    Monoid<unsigned int> w(3);
    
    (u * v * w).print();
    cout << endl;
    
    return 0;
}
