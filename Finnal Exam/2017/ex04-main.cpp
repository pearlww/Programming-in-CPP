//============================================================================
// Name        : ex04.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Exercise 4 - Parametric Double-ended Queue
//============================================================================

#include <iostream>
#include "ex04-library.h"

using namespace std;

int main() {
	mydeque<int> deque;

	deque.push_front(2);
	deque.push_front(1);
	deque.push_back(3);

	deque.print();

	cout <<"\n";
	cout << "The first element is: ";
	deque.print_front();
	cout << "The last element is: ";
	deque.print_back();

	do{
		cout <<"\n";
		cout << "pop_front(): ";
		cout <<deque.pop_front() <<"\n";
		deque.print();
	}while(deque.getSize()>0);

	cout <<"\n";
	cout << "pop_front(): ";
	cout << deque.pop_front() <<"\n";

	system("pause");
	return 0;
}

