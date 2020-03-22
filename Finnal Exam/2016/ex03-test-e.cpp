#include <iostream>
#include <string>
#include <set>
#include "ex03-library.h"

using namespace std;

int main(void){
    
    Dictionary d;
    
    d.insert_words("car","bil");
    d.insert_words("wagon","vogn");
    d.insert_words("automobile","automobil");
    
    d.insert_synonym(0,"car","auto");
    d.insert_synonym(0,"wagon","van");
    d.insert_synonym(0,"car","wagon");
    d.insert_synonym(0,"automobile","auto");
    
    d.insert_synonym(1,"bil","vogn");
    d.insert_synonym(1,"bil","automobil");
    
    set<string> s = d.translate(1,"bil");
    for(set<string>::iterator it = s.begin();
                              it != s.end(); it++)
        cout << *it << endl;
    
    return 0;
    
}
