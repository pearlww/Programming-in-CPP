//============================================================================
// Name        : live02-vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Motivation for using templates: vector of int, of double, ... all share most of the code.
//============================================================================

#include <iostream>

//#include "myVectorOfInt.h"
//#include "myVectorOfDouble.h"
#include "myVectorWithTemplates.h"
//Show differences in the two .h and .cpp files using https://www.diffnow.com/


using namespace std;

void experimentInt();
void experimentDouble();
void experimentTemplate();


int main() {
	//experimentInt();
	//experimentDouble();
	experimentTemplate();

	system("pause");
	return 0;
}


//
//void experimentInt(){
//	cout << "\n\n!!!Hello World: INT!!!" << endl;
//
//	myVectorOfInt a;
//	myVectorOfInt b(10);
//
//	for(int i=0;i<10;i++){
//		a.push_back(i);
//	}
//
//	for(int i=0;i<a.getSize();i++){
//		//cout << a.at(i) << " ";
//		cout << a[i] << " ";
//		//0 1 2 3 4 5 6 7 8 9
//	}
//	cout << "\n";
//	//0 1 2 3 4 5 6 7 8 9
//
//	for(int i=0;i<a.getSize();i++){
//		a[i] = a[i] + 2;
//	}
//	cout << "\n";
//
//	for(int i=0;i<a.getSize();i++){
//		cout << a[i] << " ";
//	}
//	//0 1 2 3 4 5 6 7 8 9
//	//2 3 4 5 6 7 8 9 10 11
//}
//
//
//
//void experimentDouble(){
//	cout << "\n\n!!!Hello World: DOUBLE!!!" << endl;
//
//	myVectorOfDouble a;
//	myVectorOfDouble b(10);
//
//	for(int i=0;i<10;i++){
//		a.push_back((double)i);
//	}
//
//	for(int i=0;i<a.getSize();i++){
//		//cout << a.at(i) << " ";
//		cout << a[i] << " ";
//		//0 1 2 3 4 5 6 7 8 9
//	}
//	cout << "\n";
//	//0 1 2 3 4 5 6 7 8 9
//
//	for(int i=0;i<a.getSize();i++){
//		a[i] = a[i] + 2.1;
//	}
//	cout << "\n";
//
//	for(int i=0;i<a.getSize();i++){
//		cout << a[i] << " ";
//	}
//	//0 1 2 3 4 5 6 7 8 9
//	//2 3 4 5 6 7 8 9 10 11
//}



void experimentTemplate(){
	cout << "\n\n!!!Hello World: STD Vectors!!!" << endl;

	myVectorWithTemplates<int> a;
	myVectorWithTemplates<int> b(10);
	//myVectorWithTemplates<double> a;
	//myVectorWithTemplates<double> b(10);

	for(int i=0;i<10;i++){
		a.push_back(i);
	}

	for(int i=0;i<a.getSize();i++){
		//cout << a.at(i) << " ";
		cout << a[i] << " ";
		//0 1 2 3 4 5 6 7 8 9
	}
	cout << "\n";
	//0 1 2 3 4 5 6 7 8 9

	for(int i=0;i<a.getSize();i++){
		a[i] = a[i] + 2;
	}
	cout << "\n";

	for(int i=0;i<a.getSize();i++){
		cout << a[i] << " ";
	}
	//0 1 2 3 4 5 6 7 8 9
	//2 3 4 5 6 7 8 9 10 11
}

