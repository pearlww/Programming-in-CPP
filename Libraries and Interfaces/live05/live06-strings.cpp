//============================================================================
// Name        : live06-strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Strings are assigned (=) using aliasing/pointers, but by making copies.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	string s1 = "aaa";

	cout << "s1 ("<< s1 <<") has length " << s1.length() <<"\n\n";

	//when you assign a string, you actually copy it.
	string s2 = s1;

	s1[1]='b';

	cout << "s1 is: " << s1 <<"\n";
	cout << "s2 is: " << s2 <<"\n";



	return 0;


//	s1 is: aba
//	s2 is: aaa


}
