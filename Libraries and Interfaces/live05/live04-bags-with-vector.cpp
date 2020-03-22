//============================================================================
// Name        : live04-bags-with-vector.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 'Advanced' bag using standard libraries
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

// enumeration type for actions on the bag
typedef enum action {add , del, sortIt, makeSet, readFile , flip , none} action;

// translation of strings into actions
action str2action(string s){
	if (s=="add") return add;
	if (s=="del") return del;
	if (s=="sortIt") return sortIt;
	if (s=="makeSet") return makeSet;
	if (s=="readFile") return readFile;
	if (s=="flip") return flip;
	return none;
}

// This time we are going to implement our bag as a vector
typedef vector<unsigned int> bag;

// function to print the content of the bag
void display(const bag & b){
	cout << "The bag is now : ";
	// this is a simple example of how to use an iterator
	// to go through all the elements in a vector
	/*for(auto e : b){
        // the iterator is used like a pointer
        // *i is used to de-reference the iterator/pointer
        cout << e << " ";
    }*/

	for(int i=0;i<b.size();i++){
		cout << b[i] << " ";
	}

	/* There are several ways of iterating a vector
     For example, using iterators the above could have been done with
     for(bag::iterator i=b.begin(); i!=b.end(); i++){
     // the iterator is used like a pointer
     // *i is used to de-reference the iterator/pointer
     cout << *i << " ";
     }
	 */

	cout << endl;
}

// this function deals with actions on a bag
void update(bag & b, action a, string s){
	unsigned int x;
	ifstream f;
	string n;
	stack<unsigned int> my_pile;

	switch(a){
	case add:
		x=stoi(s);
		// Insert at the beginning?
		b.insert(b.begin(),x);
		// Insert at the end?
		//b.push_back(x);
		break;

	case del:
		// translate a string into an integer
		x=stoi(s);
		for(bag::iterator i = b.begin(); i!=b.end(); i++){
			if(*i==x){
				i = b.erase(i);
				break;
			}
		}
		break;

	case sortIt:
		// sort a vector between to positions
		sort(b.begin(),b.end());
		break;

	case makeSet:
		sort(b.begin(),b.end());
		/*for(bag::iterator i=b.begin(); i!=b.end(); i++){
			while(i+1!=b.end() && *i==*(i+1)){
				b.erase(i+1);
			}
		}*/
		if(b.size()<2){
			break;
		}
		int curr;
		curr=b[0];
		for(int i=1;i<b.size();i++){
			if(b[i]==curr){
				b.erase(b.begin()+i);
				i--;
			}
			else{
				curr=b[i];
			}
		}

		break;

	case readFile:
		// open file s into the filestream f
		f.open(s);
		// check if the file exists
		if(f.fail()){
			cout << "Sorry, I could not open file " + s << endl;
			break;
		}
		// while we can read "words"...
		while(true) {
			f >> n;
			if(f.fail()) break;
			update(b,add,n);
		}
		f.close();
		break;

	case flip:

		// dump the bag into a stack
		/*for(auto e : b){
                my_pile.push(e);
            }*/
		for(int i=0;i<b.size();i++){
			my_pile.push(b[i]);
		}

		// dump the stack into the bag again
		b.clear();
		while(!my_pile.empty()){
			b.push_back(my_pile.top());
			my_pile.pop();
		}
		break;

	case none: break;

	default: break;

	}

	return;
}

int main(){

	vector<unsigned int> my_bag;
	//bag my_bag;
	string my_act_str;
	action my_act;
	string object;

	while(true){

		cout << endl;
		display(my_bag);
		cout << "What's next? (actions = add <x> , del <x>, sortIt, makeSet, readFile <filename>, flip)" << endl;
		cin >> my_act_str;
		my_act=str2action(my_act_str);

		// some actions require an extra argument
		if(my_act==add || my_act==del || my_act==readFile){
			cin >> object;
		}

		// resolve the action
		update(my_bag,my_act,object);
	}

	return 0;

}
