#include <iostream>
#include <vector>
#include <string>
#include "ex02-library.h"

using namespace std;

// Exercise 2
vector<string> match(vector<string> & u,
                     vector<string> & v){
    
    // Put your code here
	vector<string> w;
	if (u.empty() || v.empty())
		return w;

	vector<string> pu(u.begin(), u.end() - 1);
	vector<string> pv(v.begin(), v.end() - 1);

	if (u.back() == v.back()){
		w = match(pu, pv);
		w.push_back(u.back());
		return w;
	}

	if (match(u, pv).size() >= match(v, pu).size())
		return match(u, pv);
	else
		return match(v, pu);
    
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
