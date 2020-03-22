// This is the "header" file of the library
// It just declares the interface (types, functions, etc.)

// To avoid importing a library twice the we can make use
// of so-called conditional compilation directives
// the idea is to use a unique name to identify the library
#ifndef __my_sweet_library__
#define __my_sweet_library__

// A library, can of course need other libraries
#include<string>

using namespace std;

// This library just offers some simple functions that take in input a string, and return a new string

//This function prefixes the parameters s with "sweet"
string sweet(string s);

//This function prefixes the parameters s with "cool"
string cool(string s);

//This function changes to upper-case part of the characters of the string
string weird(string s);

#endif
