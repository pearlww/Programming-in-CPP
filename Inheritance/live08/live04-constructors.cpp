//============================================================================
// Name        : live04-constructors.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Constructors and inheritance
//============================================================================

#include <iostream>

using namespace std;

class father {
public:
	father();
	father(int u, int v);
    virtual void display(void);
    virtual ~father(){};
protected:
    int x;
private:
    int y;
};

class son : public father {
public:
    son(int u, int v);
    void display(void);
private:
    int z;
};

//father::father(){
//	x=0;
//	y=0;
//}
father::father(int u, int v){
    x = u;
    y = v;
}

// note that son's constructor
// needs to invoke father's constructor first
//son::son(int u, int v)  {
son::son(int u, int v) : father(4,4) {
    x = u;
    z = v;
}

void father::display(void) {
    cout << x << " , " << y << endl;
}

void son::display(void) {
    cout << x << " , " << z << endl;
}

int main(void){
    father f(1,1);
    son s(2,2);

    f.display();
    s.display();

    f = s;

    f.display();// 2,4   x is dynamic dispatch, z can't be accessible but constructor give(4,4)  
	            //but why?

	system("pause");
    return 0;
}
