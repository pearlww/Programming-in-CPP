#include <iostream>
#include <string>
#include "myFractions.h"

using namespace std;

int main(){
	int n, d;
	string s,op;
	
	while (true) {

		cin >> n >> s >> d;
		if (cin.fail())//if put it at the begining, it checks if cin failed in previous iteration
			break;
		fraction first(n, d);
		cin >> op;
		cin >> n >> s >> d;
		fraction second(n, d);

		switch (str2int(op)){
		case add: first.add(second); break;
		case mult:first.mult(second); break;
		case divide: first.div(second); break;
		}
		first.reduction();
		first.display();


	}

	

	system("pause");
	return 0;
}