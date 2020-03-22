#include "myVectorOfDouble.h"

#include <iostream>

//See comments in myVectorOfInt.cpp
myVectorOfDouble::myVectorOfDouble() {
	capacity=1;
	size=0;
	content=new double[capacity];
}

myVectorOfDouble::myVectorOfDouble(int initialCapacity) {
	capacity=initialCapacity;
	size=0;
	content=new double[capacity];
}

myVectorOfDouble::~myVectorOfDouble() {
	delete [] content;
}

int myVectorOfDouble::getCapacity() {
	return capacity;
}

int myVectorOfDouble::getSize() {
	return size;
}

void myVectorOfDouble::push_back(double v){
	if(size == capacity){
		resize();
	}
	content[size]=v;
	size=size+1;
}

void myVectorOfDouble::resize(){
	double * old_content = content;

	capacity=capacity*2;
	content=new double[capacity];

	for(int i=0;i<size;i++){
		content[i]=old_content[i];
	}

	delete[] old_content;
}

double myVectorOfDouble::at(unsigned int where){
	if(where >=size){
		throw std::out_of_range("you went out of range of your vector");
	}

	return content[where];
}

// Here we overload the operator _[_] to access
// myvector elements in array-style
double & myVectorOfDouble::operator[](unsigned int i)
{
    if(i>=size){
        throw std::out_of_range ("you went out of range of your myvector!");
    }
    // note that we do not return an element
    // but a reference to an element (see return type)
    return content[i];
}


// A user defined assignment operator
myVectorOfDouble & myVectorOfDouble::operator=(myVectorOfDouble & v){
    // This is what the default would do
    this->capacity = v.capacity;
    this->size = v.size;
    //this->content = v.content; // which would just copy the pointer

    delete [] this->content;
    // we need instead to create a new copy of the underlying array
    this->content = new double[this->capacity];
    for(unsigned int i=0; i<size; i++){
        this->content[i] = v.content[i];
    }
    return * this;
}

