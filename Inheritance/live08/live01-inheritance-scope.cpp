//============================================================================
// Name        : live01-inheritance-scope.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Visibility of (father) members and inheritance
//============================================================================
#include <iostream>

class A {
public:
    int x; // accessible to everyone
    int getz(); //accessible to everyone
protected:
    int y; // accessible to all derived classes (A, B, C, D)
private:
    int z; // accessible only to A


};

class B : public A {
    // x is public
	// getz() is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
	// getz() is protected
    // y is protected
    // z is not accessible from C
};

class D : private A {
    // x is private
	// getz() is private
    // y is private
    // z is not accessible from D
};

int A::getz(){
	return z;
};

int main(){
	A a;
	a.x=0;

	B b;
	b.x=0;
	b.getz();

 //   C c;
 //   c.x = 0;
	//c.getz();//why protected can't be accessible

	//D d;
	//d.x = 0;
	//d.getz();

	system("pause");
    return 0;
}
