#ifndef __ex04_library__
#define __ex04_library__

#include <string>
using namespace std;

template <class C>
class Monoid {
public:
    Monoid(C constant);
    Monoid(Monoid<C> & m1);
    Monoid(Monoid<C> & m1, Monoid<C> & m2);
    Monoid<C> & operator=(Monoid<C> & m);
    Monoid<C> & operator*(Monoid<C> & m);
    ~Monoid(void);
    C eval(C (*f)(C,C));
    int constants(void);
    void commute(void);
    void associate_left(void);
    void associate_right(void);
    void print(void);
private:
    C constant;
    Monoid<C> * m1;
    Monoid<C> * m2;
};

#endif
