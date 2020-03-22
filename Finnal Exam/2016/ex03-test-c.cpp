#include <iostream>
#include <string>
#include <set>
#include "ex03-library.h"

using namespace std;

int main(void){
    
    Dictionary d;

    d.insert_synonym(0,"car","auto");
    d.insert_synonym(0,"auto","car");
    
    d.insert_synonym(1,"bil","vogn");
    
    d.insert_synonym(2,"auto","wagen");
    
    return 0;
    
}
