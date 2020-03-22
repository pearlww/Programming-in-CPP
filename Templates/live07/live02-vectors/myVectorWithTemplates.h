#ifndef MYVECTORWITHTEMPLATES_H_
#define MYVECTORWITHTEMPLATES_H_

// This implementation of a vector class is based
// on the one of previous weeks.
// The difference is that the one in this file
// is generic: it provides support for vectors of any type
// not just integers.

// The class vector is now "templated"
// The template has one parameter: the base type/class T
template <class T>
class myVectorWithTemplates {
	// Below we have replaced every occurrence of "double"
	// related to vector elements by "T"
	// Moreover, we have replaced all occurrences of "myVectorWithTemplates"
	// by myVectorWithTemplates<T>
private:
	T * content;							// note the use of T
	int size;
	int capacity;
	void resize();

public:
	myVectorWithTemplates();
	myVectorWithTemplates(int initialCapacity);

	~myVectorWithTemplates();


	int getCapacity();
	int getSize();
	void push_back(T v);					// note the use of T

	T at(unsigned int where);			// note the use of T
	T & operator[](unsigned int where);	// note the use of T

	myVectorWithTemplates<T> & operator=(myVectorWithTemplates<T> &);

};


//We cannot define a template class in a .h and a .cpp.
//We have to do everything in the .h file.
//Here we do a workaround: we use extension '.tpp' rather than '.cpp', and we import it here.
#include "myVectorWithTemplates.tpp"

#endif /* MYVECTORWITHTEMPLATES_H_ */
