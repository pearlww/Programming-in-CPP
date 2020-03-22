#ifndef __ex04_library__
#define __ex04_library__

#include <string>

using namespace std;

template <class C>
class Monoid {
    
public:
    Monoid(C constant);
    Monoid<C> operator*(Monoid<C> & m);
    Monoid(Monoid<C> & m1, Monoid<C> & m2);
    C eval(C (*f)(C,C));
    void print(void);

private:
    Monoid(Monoid<C> & m1);
    C constant;
    Monoid<C> * m1;
    Monoid<C> * m2;
    
};

#endif
