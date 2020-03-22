#include <iostream>
#include <string>
#include "ex04-library.h"

using namespace std;

string reverse(string u, string v){
    return v + u;
}

unsigned int mult(unsigned int u, unsigned int v){
    return u * v;
}

unsigned int max(unsigned int u, unsigned int v){
    return u > v ? u : v;
}


int main(void){
    Monoid<string> h("Hello");
    Monoid<string> b(" ");
    Monoid<string> o("world");
    Monoid<string> a("and");
    Monoid<string> e("everybody");
    Monoid<string> f("else!");

    cout << h.eval(reverse);
    cout << endl;
    
    cout << (h * b * o * b * a * b * e * b * f).eval(reverse);
    cout << endl;
    
    Monoid<unsigned int> u(2);
    Monoid<unsigned int> v(3);
    Monoid<unsigned int> w(5);
    
    Monoid<unsigned int> x1(u,v);
    Monoid<unsigned int> x2(v,w);
    Monoid<unsigned int> y1(x1,w);
    Monoid<unsigned int> y2(u,x2);
    cout << y1.eval(mult);
    cout << endl;
    cout << y2.eval(mult);
    cout << endl;
    
    cout << (u * v * w).eval(max);
    cout << endl;
    
    return 0;
}
