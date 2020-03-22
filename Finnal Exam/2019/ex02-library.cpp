#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n){
	//put your code here

	if (n+1>0){
		char last_char = s[n];
		string t=reverse(s,n-1);
		return t.insert(0,1,last_char);
	}
	else{
		return "";
	}

}

//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2){
	//put your code here
	if (s == "")
		return true;
	if (s[n1] != s[n2]) 
		return false;
	if (n1 >= n2) 
		return true;
	else{
		return isPalindrome(s, n1 + 1, n2 - 1);
	}
}

//Exercise 2 (c) Implement this function
int distancePalindrome(string s, int n1, int n2){
	//put your code here
	if (n1 >= n2)
		return 0;

	if (s[n1] != s[n2]){
		return 1 + distancePalindrome(s, n1 + 1, n2 - 1);
	}
	else
		return distancePalindrome(s, n1 + 1, n2 - 1);


}