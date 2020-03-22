#include <iostream>
#include <vector>
#include <string>
#include "ex02-library.h"

using namespace std;

// Exercise 2
vector<string> match(vector<string> & u,
                     vector<string> & v){
	vector<string> v1, v2;

	if (u.empty() || v.empty())
		return v1;

	vector<string> tu(u.begin() + 1, u.end());
	vector<string> tv(v.begin() + 1, v.end());

	if (u[0] == v[0]){
		v1.push_back(u[0]);
		v2=match(tu, tv);
        v1.insert(v1.end(), v2.begin(), v2.end());
		//or
		//v2.insert(v2.begin(),v1); return v2;
		return v1;
	 
	}
	if (match(u, tv).size() >= match(tu, v).size()){
		return match(u, tv);
	}
	else{
		return match(tu, v);
	}
    // Put your code here
    
}

// Do not modify
vector<string> read_until(string stop){
    vector<string> u;
    string e;
    while(true){
        cin >> e;
        if(cin.fail() || e == stop) break;
        u.push_back(e);
    }
    return u;
}

// Do not modify
void display(vector<string> & u){
    for(unsigned int i=0; i<u.size(); i++)
        cout << u[i] << " " ;
    cout << endl;
}
