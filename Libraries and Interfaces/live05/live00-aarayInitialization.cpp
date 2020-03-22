//============================================================================
// Name        : live00-aarayInitialization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Arrays' entries are not necessarily initialized to zero!
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout <<"\nDynamically allocated array\n";


	
	int n=5;
	int * array = new int[n];
	for(int i=0;i<n;i++){
		cout << array[i] << ' ';
	}
	cout <<"\n";
	delete[] array;

	array = new int[n]();
	for(int i=0;i<n;i++){
		cout << array[i] << ' ';
	}
	cout <<"\n";

	delete[] array;
	

	cout <<"\nStatically allocated array\n";
	int arrayStatic[5];
	for(int i=0;i<5;i++){
		cout << arrayStatic[i] << ' ';
	}
	cout <<"\n";

	int arrayStaticTwo[5]={};
	for(int i=0;i<5;i++){
		cout << arrayStaticTwo[i] << ' ';
	}
	cout <<"\n";

	system("pause");
	return 0;
}
