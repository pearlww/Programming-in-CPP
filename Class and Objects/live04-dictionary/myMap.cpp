#include "myMap.h"
#include <iostream>

myMap::myMap(string n){
	name=n;
};

myMap::~myMap(){
	cout << "Deleting dictionary " << name << "..." << endl;
}

void myMap::insert(string key, string entry){
	int i=contains(key);
	if (i==-1){
		keys.push_back(key);
		entries.push_back(entry);
	}
	else{
		entries[i]=entry;
	}
};

int myMap::contains(string key) const{
	for(int i=0; i<  keys.size(); i++){
		if (keys[i]==key) return i;
	}
	return -1;
};

string myMap::find(string key){
	int i=contains(key);
	//  keys[0]="";
	if (i==-1) return NOT_FOUND;
	return entries[i];
};
