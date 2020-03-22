
#include "myVectorAsLinkedList.h"
#include <iostream>

using namespace std;

// The constructor
myVector::myVector(void){
    vsize = 0;
    first = nullptr ;
    return;
}


// Destructor method
myVector::~myVector(void){
    // We need to deallocate the array
    erase();
    return;
}

unsigned int myVector::size(void){
    return vsize;
}

// push_back implemented using recursion
// it can be also implemented with a loop

void myVector::push_back(int x){

	Node<int> * newElement = new Node<int>;
	newElement->content = x;
	newElement->next = nullptr;

	if(first==nullptr){
		first=newElement;
		vsize=1;
	}
	else{
		push_backR(first,newElement);
	}
}

void myVector::push_backR(Node<int> * currentElement, Node<int> * newElement){
	if(currentElement->next==nullptr){
		currentElement->next=newElement;
		vsize++;
	}
	else{
		push_backR(currentElement->next,newElement);
	}
}

/*
void myVector::push_backR(int x, Node<int> * & pp){

    // check if pp is nullptr
    // this means the either the list is empty
    // or we arrived to the end
    if (pp == nullptr){
        // create a new node for x
        Node<int> * p;
        p = new Node<int>;
        p->content = x;
        p->next = nullptr;
        // update first to point to the new element
        pp = p;
        vsize = vsize + 1;
        return;
    }

    // otherwise, push back in the rest of the list
    push_backR(x,pp->next);

}
*/

// method "at" implemented with a loop
// it can of course be implemented with recursion as well

int myVector::at(unsigned int i){
	return at_iter(i);
	//return at_rec(first,i);
}

int myVector::at_iter(unsigned int i){
    // we check if we are accessing an element of the myVector
    // otherwise we raise an error
    if(i >= vsize){
        throw std::out_of_range ("you went out of range of your myVector!");
    }

    // we iterate through the list until we find the i-th
    // element or we reach the end of the list
    unsigned int j = 0;
    for(Node<int> * p = first; p != nullptr; p = p->next){
        if (j == i){
        		return p->content;
        }
        j = j + 1;
    }
    throw std::out_of_range ("you went out of range of your myVector!");
}

int myVector::at_rec(Node<int>* currentElement,unsigned int i){
	if(currentElement==nullptr){
		throw std::out_of_range ("you went out of range of your myVector!");
	}
	else{
		if(i==0){
			return currentElement->content;
		}
		else{
			return at_rec(currentElement->next,i-1);
		}
	}
}

// Here we overload the operator _[_] to access
// myVector elements in array-style
int & myVector::operator[](unsigned int i)
{
    if(i>=vsize){
        throw std::out_of_range ("you went out of range of your myVector!");
    }

    // note that we do not return an element
    // but a reference to an element (see return type)
    unsigned int j = 0;
    for(Node<int> * p = first; p != nullptr; p = p-> next){
        if (j == i) {
        		return p->content;
        }
        j = j + 1;
    }
    throw std::out_of_range ("you went out of range of your myVector!");


	//or you can just write:
	//return at(i);

}

// A user defined assignment operator
myVector & myVector::operator=(myVector & v){

    // delete the current list
    erase();

    // copy v
    for(unsigned int i=0; i<v.size(); i++){
        push_back(v[i]);
    }
    //vsize = v.size();

    return * this;
}

// Erase of a myVector, recursively
void myVector::erase(){
    eraseR(first);
    first = nullptr;
    vsize = 0;
}

void myVector::eraseR(Node<int> * p){
    if (p == nullptr){
    		return;
    }
    //Node<int> * q = p ;
    //p = p->next;
    eraseR(p->next);
    delete p;
    //eraseR(p->next);
}

