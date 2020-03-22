// This is the implementation file of the library
// It just implements the interface (types, functions, etc.)

//#ifndef __my_sweet_library__
//#define __my_sweet_library__

// A library, can of course need other libraries
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

// Now we have to implement the function that was
// declared in the interface
string sweet(string s){
    return "sweet " + s + " :) ";
}

string cool(string s){
    return "cool " + s + " 8) ";
}

string weird(string s){
    for(int i=0; i<s.length(); i++){
        if(rand()%2) s[i]=toupper(s[i]);
        if(rand()%2) s[i]=tolower(s[i]);
    }
    return s ;
}

//#endif
