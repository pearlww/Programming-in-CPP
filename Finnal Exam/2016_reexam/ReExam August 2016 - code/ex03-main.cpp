#include <iostream>
#include <string>
#include <set>
#include "ex03-library.h"

using namespace std;

int main(void){
    Dictionary d;
    set<string> s;
    
    d.insert_words("car","bil");
    cout << d.get_word("english","car") << endl;
    cout << d.get_word("danish","bil") << endl ;
    
    d.insert_synonym("english","car","auto");
    
    s = d.get_synonyms("english","auto");
    for(set<string>::iterator it = s.begin();
        it != s.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    s = d.translate("danish","bil");
    for(set<string>::iterator it = s.begin();
        it != s.end(); it++)
        cout << *it << " ";
    cout << endl;
    
	system("pause");
    return 0;
}
