#ifndef __ex03_library__
#define __ex03_library__

#include <map>
#include <set>
#include <string>

using namespace std;

class Dictionary {
    
public:
    void insert_words(string u, string v);
    string get_word(string lang, string u);
    void insert_synonym(string lang, string u, string v);
    set<string> get_synonyms(string lang, string u);
    set<string> translate(string lang, string u);
    
private:
    map<string,string> english2danish;
    map<string,string> danish2english;
    map<string,set<string> > english_synonyms;
    map<string,set<string> > danish_synonyms;
    
};

#endif
