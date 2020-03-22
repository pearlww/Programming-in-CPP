//============================================================================
// Name        : live02-refinement.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Static method dispatch vs dynamic method dispatch
//============================================================================

#include <iostream>

using namespace std;

class father {
public:
	void f(void) { cout << "Calling father::f\n"; };
	virtual void g(void) { cout << "Calling father::g\n"; };
	virtual ~father() {};

};

class son : public father {
public:
	void f(void) { cout << "Calling son::f\n"; };
	//virtual void f(void) { cout << "Calling son::f\n"; };
	void g(void) { cout << "Calling son::g\n"; };
};

class nephew : public son {
public:
	//virtual void f(void) { cout << "Calling nephew::f\n"; };
	void f(void) { cout << "Calling nephew::f\n"; };
	void g(void) { cout << "Calling nephew::g\n"; };
};

void testFatherSon();
void testFatherSonNephew();

int main(void){
	testFatherSon();
	cout <<"\n";
	testFatherSonNephew();
	system("pause");
}

void testFatherSon(){
	cout << "###############\n";
	cout << "Test father-son\n";
	cout << "###############\n";
	son * s = new son();
	father * p = s;

	// Static dispatch of 'f': binding based on p’s type
	cout <<"Static dispatch\n";
	s->f();  // calls son::f()
	p->f();  // calls father::f()



	// Dynamic dispatch: binding based on actual type of object pointed by p
	cout <<"\nDynamic dispatch\n";
	s->g();  // calls son::g()
	p->g();  // calls son::g()
}

void testFatherSonNephew(){
	cout << "######################\n";
	cout << "Test father-son-nephew\n";
	cout << "######################\n";
	nephew * n = new nephew();
	son * s = n;
	father * p = s;

	// Static dispatch of 'f': binding based on p’s type
	cout <<"Static dispatch\n";
	n->f();  // calls nephew::f()
	s->f();  // calls son::f()
	p->f();  // calls father::f()



	// Dynamic dispatch: binding based on actual type of object pointed by p
	cout <<"\nDynamic dispatch\n";
	n->g();  // calls nephew::g()
	s->g();   // calls nephew::g()
	p->g();   // calls nephew::g()
}
