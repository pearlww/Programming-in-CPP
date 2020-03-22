#include <iostream>
#include <string>
#include <set>
#include "ex03-library.h"

using namespace std;

int main(void){
    
    Dictionary d;
    
    d.insert_words("car","bil");
    d.insert_words("wagon","vogn");
    
    d.insert_synonym(0,"car","wagon");
    d.insert_synonym(1,"vogn","bil");

    cout << d.get_word(0,"car") << endl;
    cout << d.get_word(1,"car") << endl;
    cout << d.get_word(2,"car") << endl;
    cout << d.get_word(0,"bil") << endl;
    cout << d.get_word(1,"bil") << endl;
    cout << d.get_word(2,"bil") << endl;
    cout << d.get_word(0,"wagon") << endl;
    cout << d.get_word(1,"wagon") << endl;
    cout << d.get_word(2,"wagon") << endl;
    cout << d.get_word(0,"vogn") << endl;
    cout << d.get_word(1,"vogn") << endl;
    cout << d.get_word(2,"vogn") << endl;

    return 0;
    
}
