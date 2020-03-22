//============================================================================
// Name        : live04-bags.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Playing with bags...
//============================================================================

#include <iostream>
#include <set> // http://www.cplusplus.com/reference/set/set/
#include <string>

using namespace std;

// enumeration type for actions on the bag
enum action {add , quit, none};

// translation of strings into actions
action str2action(string s){
	if (s=="add") return add;
	if (s=="quit") return quit;
	return none;
}

// a place in the bag (full declaration)
struct item {
	unsigned int val;
	item * next;
};

#define BAG_AS_ARRAY_SIZE 10

// We will implement a bag in three ways
struct bag {
	bool as_array[BAG_AS_ARRAY_SIZE];   // using arrays
	item * as_linked_items;             // using linked lists
	set<unsigned int> as_set;           // using sets
};
// We do it for pedagogical purposes
// mainly to emphasize the differences
// We will try to keep the three bags aligned
// but (for pedagogical purposes) the following code fails in doing so

// Simple function to initialise the bag
//!!!!!call by reference
void initialise(bag & b){

	// Array
	for(int i=0; i<BAG_AS_ARRAY_SIZE; i++){
		b.as_array[i] = false;
	}

	//Linked-list
	b.as_linked_items = nullptr;

	// Set: nothing to be done :)
}

// function to display the content of the bag
void display_bag(bag b){

	cout << "The bag is : " << endl;

	// Array
	cout << " - (A) - : " ;
	for(int i=0; i<BAG_AS_ARRAY_SIZE; i++){
		if(b.as_array[i])
			cout << i << " " ;
	}
	cout << endl;



	// Linked List
	cout << " - (L) - : " ;
	item * p = b.as_linked_items;
	while(p != nullptr){
		cout << p->val << " ";
		p = p->next; // same as (*p).next
	}
	cout << endl;

	// Set
	cout << " - (S) - : ";
	/*
	for(auto e : b.as_set){
		cout << e << " " ;
	}
	*/
	std::set<unsigned int>::iterator it; //is it a pointer?
	for (it = b.as_set.begin(); it != b.as_set.end(); ++it){
		unsigned int e = *it;
		cout << e << " " ;
	}

	cout << endl;

	return;

}

//!!!!!call by reference
void insert(bag &b,unsigned int x){

	// Array
	b.as_array[x] = true;

	// Linked list
	// we allocate a new place for the new value
	item * i = new item;
	i->val = x;
	//(*i).val=x;

	// we make it point to the bag
	i->next = b.as_linked_items;
	// we set the bag now to start with the new place
	b.as_linked_items = i;

	// Set
	b.as_set.insert(x);

}

// this function deals with actions on a bag
//!!!!!call by reference
void update(bag &b, action a, unsigned int x){

	switch(a){
	case add:
		insert(b,x);
		break;
	case quit:
		break;
	case none:
		break;
	default:
		break;
	}

	return;
}

int main(){

	bag my_bag;
	string my_act_str;
	unsigned int x;

	initialise(my_bag);

	bool go_on = true;
	while(go_on){

		display_bag(my_bag);
		cout << "What's next? (actions = add x , quit)" << endl;
		cin >> my_act_str;
		action act = str2action(my_act_str);
		if(act==quit){
			go_on=false;
		}
		else{
			cin >> x;
			update(my_bag,act,x);
		}

	}

	return 0;

}
