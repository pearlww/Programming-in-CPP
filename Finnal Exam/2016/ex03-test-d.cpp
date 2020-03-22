#include <iostream>
#include <string>
#include <set>
#include "ex03-library.h"

using namespace std;

int main(void){
    
    Dictionary d;
    
    d.insert_synonym(0,"car","auto");
    d.insert_synonym(0,"auto","car");
    d.insert_synonym(0,"car","wagon");
    d.insert_synonym(0,"car","vehicle");
    
    d.insert_synonym(1,"bil","vogn");
    d.insert_synonym(1,"bil","automobil");
    
    set<string> s = d.get_synonyms(0,"car");
    for(set<string>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    
    s = d.get_synonyms(1,"bil");
    for(set<string>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    
    return 0;
    
}
