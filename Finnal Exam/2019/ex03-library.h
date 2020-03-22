#ifndef EX03_LIBRARY_H_
#define EX03_LIBRARY_H_

#include <string>
#include <vector>
#include <map>

using namespace std;

class WordsList {
private:
	vector<string> allWords;
	map<string,int> wordsToPalindromeDistance;
public:
	WordsList();
	void print();
	int distancePalindrome(string s);
	void addWord(string word);
	int palindromeWords();
};

#endif /* EX03_LIBRARY_H_ */