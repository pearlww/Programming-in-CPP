#include "myVector.h"

#include <iostream>

// The constructor
myVector::myVector(void) /*: myVector(1)*/{
    // We decide here to start with a small capacity
    capacity = 1;
    vsize = 0;
    // We allocate the space we need dynamically
	//the size of array is 1;
    content = new int[capacity];
    return;
}

// The constructor
myVector::myVector(int initialCapacity){
    // We decide here to start with a small capacity
    capacity = initialCapacity;
    vsize = 0;
    // We allocate the space we need dynamically
	//the size of array is initialcapacity
    content = new int[capacity];
    return;
}

// Destructor method
myVector::~myVector(void){
    // We need to deallocate the array
    delete [] content;
    return;
}

void myVector::resize(){
    // save pointer to current array
    int * old_content = content;

    // allocate new array: we try to double the current capacity
    capacity =  capacity * 2;
    content = new int[capacity];

    // copy content
    for(unsigned int i=0; i<vsize; i++){
        content[i] = old_content[i];
    }

    // delete old array
    delete [] old_content;
}

//int *p=new int;
//delete p;
//int *a=new int[5];
//delete [] a;

unsigned int myVector::size(void){
    return vsize;
}

void myVector::push_back(int x){

    // resize array if full
    if(vsize == capacity){
        resize();
    }

    // insert new element
    content[vsize] = x;
    vsize = vsize + 1;

}

int myVector::at(unsigned int i){
    // we check if we are accessing an element of the myvector
    // otherwise we raise an error
    if(i >= vsize){
        throw std::out_of_range ("you went out of range of your myvector!");
    }
    return content[i];
}

// Here we overload the operator _[_] to access
// myvector elements in array-style
int & myVector::operator[](unsigned int i)
{
    if(i>=vsize){
        throw std::out_of_range ("you went out of range of your myvector!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    return content[i];
}


// A user defined assignment operator
//myVector & myVector::operator=(myVector & v){
//
//    // This is what the default would do
//    this->capacity = v.capacity;
//    this->vsize = v.vsize;
//    //this->content = v.content; // which would just copy the pointer
//
//    delete [] this->content;
//    // we need instead to create a new copy of the underlying array
//    this->content = new int[this->capacity];
//    for(unsigned int i=0; i<vsize; i++){
//        this->content[i] = v.content[i];
//    }
//
//	//"this" is a pointer point to self
//    return * this;
//}

