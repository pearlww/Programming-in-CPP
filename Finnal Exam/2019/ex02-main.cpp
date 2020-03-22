#include <iostream>

#include "ex02-library.h"
using namespace std;

void testReverse(string s){
	string rev = reverse(s,s.length()-1);
	cout << s << " | " << rev << endl;
}

void testPalindrome(string s){
	bool pal = isPalindrome(s,0,s.length()-1);
	cout << s << ((pal)?" is":" is not");
	cout <<" palindrome" << endl;
}

void testDistancePalindrome(string s){
	int k = distancePalindrome(s,0,s.length()-1);
	cout << s << " requires " << k;
	cout << " changes to be palindrome"<< endl;
}

int main() {
	string words[] = {"","a","aa","ab","aba","abc",
		"abccba","abcdba","abcdea","abcdef","abcdefg"};
	int length=11;

	cout << "REVERSE" << endl;
	for(int i=0;i<length;i++){
		testReverse(words[i]);
	}

	cout << endl << "PALINDROME" << endl;
	for(int i=0;i<length;i++){
		testPalindrome(words[i]);
	}

	cout << endl << "DISTANCE-PALINDROME" << endl;
	for(int i=0;i<length;i++){
		testDistancePalindrome(words[i]);
	}

	system("pause");

	return 0;
}