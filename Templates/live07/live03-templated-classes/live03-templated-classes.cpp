//============================================================================
// Name        : live03-templated-classes.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : An example of templated class with two parameters
//============================================================================

#include <iostream>
#include <vector>
#include <string>

// Example based on pairs
// see http://www.cplusplus.com/reference/utility/pair/

using namespace std;

template <class A, class B>
class paar {

public:
    paar(A a, B b);
    A first(void);
    B second(void);
    paar<B,A> flip(void);
    paar<A,B> & operator=(paar<A,B> & p);
    void display(void);

private:
    A a;
    B b;

};

template <class A, class B>
paar<A,B>::paar(A a, B c){
    this->a = a;
    //(*this).a =a;
    //this->b = b;
    this->b = c;
}

template <class A, class B>
A paar<A,B>::first(void){
    return a;
}

template <class A, class B>
B paar<A,B>::second(void){
    return b;
}

template <class A, class B>
paar<B,A> paar<A,B>::flip(void){
    paar<B,A> p(b,a);
    return p;
}

template <class A, class B>
paar<A,B> & paar<A,B>::operator=(paar<A,B> & p){
    a = p.first();
    b = p.second();
	return *this;//return is necessary
}

template <class A, class B>
void paar<A,B>::display(void){
    cout << "<" << a << "," << b << ">" << endl;
}


// some templated free functions for pairs

// test if two pairs can be matched/plugged
template <class A, class B, class C>
bool match(paar<A,B> p, paar<B,C> q){
    return (p.second() == q.first());
}

// join a pair by taking the first component of the first pair
// and the second component of the second pair
template <class A, class B, class C>
paar<A,C> join(paar<A,B> p, paar<B,C> q){
    paar<A,C> r(p.first(),q.second());
    return r;
}

int main(void){

    paar<string,int> a("Alice",1);
    paar<string,int> b("Bob",2);

    //paar<vector<int>,int> X(a,2);

    paar<int,int> likes(1,2);
    vector<int> v;
    //paar<vector<int>,int> X(v,1);
    a.display();
    b.display();
    likes.display();

	

    if( match<string,int,int>(a,likes)
     && match<int,int,string>(likes,b.flip()) ){
        paar<string,string> gossip = join<string,int,string>(a,b.flip());//the "=" here is not overload?
        cout << "gossip alert: ";
        gossip.display();
        cout << endl;
    }
    cout << endl;
	system("pause");
    return 0;
}



