#include <iostream>

#include "ex03-library.h"
using namespace std;

int main() {
	string words[] = {"","a","aa","ab","aba","abc",
		"abccba", "abcdba","abcdea","abcdef","abcdefg"};
	int length=11;

	WordsList wl;
	cout << "The initial configuration" << endl;
	wl.print();
	
	cout << endl;
	cout << "Are the strings in 'words' palindromes?";
	cout << endl;
	for(int i=0;i<length;i++){
		int dist = wl.distancePalindrome(words[i]);
		cout << words[i] << " requires " << dist ;
		cout << " changes to be palindrome" << endl; 
	}
	
	cout << endl ;
	int pWords = wl.palindromeWords();
	cout << "The initial configuration contains " ;
	cout << pWords << " palindromes" << endl;

	for(int i=0;i<length;i++){
		wl.addWord(words[i]);
	}
	cout << endl << "The final list" << endl;
	wl.print();

	cout << endl;
	pWords = wl.palindromeWords();
	cout << "The final list contains ";
	cout << pWords << " palindromes" << endl;

	system("pause");

	return 0;
}