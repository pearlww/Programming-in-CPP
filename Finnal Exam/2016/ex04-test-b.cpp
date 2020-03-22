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
    
    Monoid<string> m1(h,b);
    Monoid<string> m2(m1,o);
    Monoid<string> m3(m2,b);
    Monoid<string> m4(m3,a);
    Monoid<string> m5(m4,b);
    Monoid<string> m6(m5,e);
    Monoid<string> m7(m6,b);
    Monoid<string> m8(m7,f);

    m8.print();
    cout << endl;
    
    Monoid<unsigned int> u(1);
    Monoid<unsigned int> v(2);
    Monoid<unsigned int> w(3);
    
    Monoid<unsigned int> x1(u,v);
    Monoid<unsigned int> x2(v,w);
    Monoid<unsigned int> y1(x1,w);
    Monoid<unsigned int> y2(u,x2);
    y1.print();
    cout << endl;
    y2.print();
    cout << endl;
    
    return 0;
}
