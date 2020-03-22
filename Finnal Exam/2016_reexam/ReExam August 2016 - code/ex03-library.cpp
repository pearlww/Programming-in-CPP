#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(a)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    english2danish[u] = v;
    danish2english[v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(string lang, string u){
	if (lang == "english")
		return (english2danish.find(u)!=english2danish.end()? english2danish[u]:"#unknown#");
	if (lang == "danish")
		return  (danish2english.find(u) != danish2english.end() ? danish2english[u] : "#unknown#");
	else
		return "#unknown#";
}

// Exercise 3(c)
void Dictionary::insert_synonym(string lang, string u,
                                     string v){
    // Put your code here
	if (lang == "english"){
		english_synonyms[u].insert(v);
	    english_synonyms[v].insert(u);
	}
		
	if (lang == "danish"){
		danish_synonyms[u].insert(v);
		danish_synonyms[v].insert(u);
	}
		
	else
		return;
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(string lang, string u){
    // Put your code here
	if (lang == "english")
		return english_synonyms[u];
	if (lang == "danish")
		return danish_synonyms[u];

}

// Exercise 3(e)
set<string> Dictionary::translate(string lang, string u){
    // Put your code here
	set<string> s;
	if (lang == "english")
	     s = get_synonyms("danish", get_word(lang, u));
	if (lang == "danish")
		s = get_synonyms("english", get_word(lang, u));

	s.insert(get_word(lang, u));
	return s;
}

