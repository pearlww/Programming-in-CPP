
#ifndef MYSETASLINKEDLIST_H_
#define MYSETASLINKEDLIST_H_

#include "linked-list.h"

using namespace std;

template<class C>
class Set{

public:
	// A constructor
	Set();

	// check emptiness
	bool empty();

	// add an element to the set
	void insert(C e);

	// check if an element is in the set
	bool contains(C e);

	// delete an element from the set
	void del(C e);

	// extract some element from the set
	C extract(void);

	// Destructors are needed since the internal representation
	// is based on dynamically allocated list elements
	~Set();

	void print();

	// This method tests if two sets are equal
	// Is this a correct implementation?
	bool operator ==(const Set &S) const;

private:
	// Internal implementation of the set as a linked list
	Node<C> * first;

	//Internal utility methods
	void insertOrdered(C e);
	void insertOrderedRec(Node<C> * newElement, Node<C> * prevElement, Node<C> * currentElement);
	bool containsR(C e, Node<C> * p);
	// delete an element from the set
	void delR(C e, Node<C> * prevElement, Node<C> * currentElement);
	void printR(Node<C> * n);
	bool equal(Node<C> * p, Node<C> * q) const;

};

#include "mySetAsLinkedList.tpp"

#endif /* MYSETASLINKEDLIST_H_ */

