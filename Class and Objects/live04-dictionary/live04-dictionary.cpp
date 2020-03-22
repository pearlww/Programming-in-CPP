//============================================================================
// Name        : live04-dictionary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Custom implementation of a map/dictionary
//============================================================================




#include <iostream>
#include "myMap.h"

using namespace std;

// Testprogram:
int main(){
  myMap dan2eng("Danish-to-English");
  myMap *eng2dan=new myMap("English-to-Danish");
  eng2dan->insert("black","sort");

  //dan2eng.entries.push_back("lala");

  dan2eng.insert("groen","black");
  dan2eng.insert("blaa","blue");
  dan2eng.insert("roed","red");
  dan2eng.insert("groen","green");

  cout << "groen -> " << dan2eng.find("groen") << "\n";
  cout << "black -> " << eng2dan->find("black") << "\n";

  delete eng2dan;
}
