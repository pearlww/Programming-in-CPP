#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList(){
	allWords.push_back("121");
	wordsToPalindromeDistance["121"]=0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"]=1;
}

//Exercise 3 (a) implement this method
void WordsList::print(){
	//put your code here
	cout << allWords.size() << " " << "words:";
	for (int i = 0; i < allWords.size();i++){
		cout << " " << allWords[i] << " "<< "(" << distancePalindrome(allWords[i]) << ")";
	}
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s){
	//put your code here
	int d = 0;
	int n = s.size();
	if (n % 2 == 0){
		for (int i = 0; i < n/2; i++){
			if (s[i] != s[n-1 - i])
				d++;
		}
	}
	else{
		for (int i = 0; i < (n-1) / 2; i++){
			if (s[i] != s[n-1 - i])
				d++;
		}
	}
	return d;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word){
	//put your code here
	allWords.push_back(word);
	wordsToPalindromeDistance[word] = distancePalindrome(word);
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords(){
	//put your code here
	int n = 0;
	for (int i = 0; i < allWords.size(); i++){
		if (distancePalindrome(allWords[i]) ==0)
			n++;
	}
	return n;
}