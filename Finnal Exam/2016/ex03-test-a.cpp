#include <iostream>
#include <string>
#include <set>
#include "ex03-library.h"

using namespace std;

int main(void){
    
    Dictionary d;
    string s;
    
    d.insert_words("car","bil");
    s = d.get_word(0,"car");
    s = d.get_word(1,"car");
    s = d.get_word(2,"car");
    s = d.get_word(3,"car");
    
    return 0;
    
}
