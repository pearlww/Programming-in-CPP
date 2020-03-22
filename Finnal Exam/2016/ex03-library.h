#ifndef __ex03_library__
#define __ex03_library__

#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Dictionary {
    
public:
    Dictionary(void);
    void insert_words(string u, string v);
    string get_word(int lang, string u);
    void insert_synonym(int lang, string u, string v);
    set<string> get_synonyms(int lang, string u);
    set<string> translate(int lang, string u);
    
private:
    vector<map<string,string> > words;
    vector<map<string,set<string> > > synonyms;
    
};

#endif
