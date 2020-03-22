#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(a)
Dictionary::Dictionary(void){
    // Put your code here
	words.resize(2);
	synonyms.resize(2);
}

// Exercise 3(b)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    words[0][u] = v;
	words[1][v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(int lang, string u){
	if (words[lang].find(u) != words[lang].end())
		return words[lang][u];
	else
		return "";
    

}

// Exercise 3(c)
void Dictionary::insert_synonym(int lang, string u, string v){
    // Put your code here
	if (lang != 0 && lang != 1)
		return;
	synonyms[lang][u].insert(v);
	synonyms[lang][v].insert(u);
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(int lang, string u){
    // Put your code here
	if (synonyms[lang].find(u) != synonyms[lang].end())
	     return synonyms[lang][u];
	else{
		set<string> A;
		return A;
	}
		
}

// Exercise 3(e)
set<string> Dictionary::translate(int lang, string u){
    // Put your code here
	set<string> s1,s2,s3;
	s1.insert(get_word(lang,u));
	s2 = get_synonyms(lang, u);
	s1.insert(s2.begin(), s2.end());
	for (auto it = s2.begin(); it != s2.end(); ++it){
		s1.insert(get_word(lang, *it));
		s3 = get_synonyms(lang, *it);
		s1.insert(s3.begin(), s3.end());
	}
	return s1;
}

