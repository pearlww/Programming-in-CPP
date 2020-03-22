//============================================================================
// Name        : live03-vectorsAndMemoryAllocation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
// Description : Containers & memory allocation. Containers, e.g. vectors, should always be passed by reference/
//============================================================================

#include<vector>
#include <iostream>

using namespace std;

vector<int> createVector(){
	vector<int> v(10);
	return v;
}


/*
vector<int>* createVectorWRONG(){
	vector<int> v(10);
	return 	&v;
}
*/

//copy of vector
void badIdea(vector<int> v){
	for(int i=0;i<v.size();i++){
		v[i]=v[i]-1;
	}
}

//call by reference
void goodIdea(vector<int> &v){
	for(int i=0;i<v.size();i++){
		v[i]=v[i]-1;
	}
}

/*
void f1(vector<int> & v)
{
	cout << "v[0] is: " << v[0] << "\n";
	v[0]=2*v[0];
	cout << "v[0] is: " << v[0] << "\n\n";
}

void f2(const vector<int> & v)
{
	cout << "v[0] is: " << v[0] << "\n";
	//v[0]=2*v[0];
	cout << "v[0] is: " << v[0] << "\n\n";
}
*/

int main()
{
	vector<int> v1;
	//const vector<int> v2;
	//vector<int> v2;

	v1.push_back(1);
	//v2.push_back(2);

	//f1(v1);
	//f2(v2);


	for(int i=0;i<v1.size();i++){
		cout << v1[i] << ' ';
	}
	badIdea(v1);
	for(int i=0;i<v1.size();i++){
		cout << v1[i] << ' ';
	}
	goodIdea(v1);
	for(int i=0;i<v1.size();i++){
		cout << v1[i] << ' ';
	}

	return 0;
}
