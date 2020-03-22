#ifndef __v2d__
#define __v2d__

#include <cmath>

//declaration
template <class T>
class v2d{

public:
    // standard constructor
    // builds a vector (a,b)
	v2d(T a, T b);
    
    // copy constructor
    // builds a vector that is exactly as v
	v2d(const v2d<T> & v);
    
    // destructor
    ~v2d(void);
    
    // assignment
    // updates the vector to make it as v
	v2d<T> & operator=(const v2d<T> &v);
    
    // vector addition
    // updates the vector by adding v
	v2d<T> & operator+(const v2d<T> &v);
    
    // scalar multiplication
    // updates the vector by scaling by k
    v2d<T> & operator*(double k);
    
    // scalar product of the current vector
    // by another vector v 
	double operator*(const v2d<T> &v);
    
    // computes the length of a vector
    double length(void);

private:
    // internal representation of a vector
    // with just two doubles x and y
    T x;
    T y;
    
};



// implementation
template <class T>
v2d<T>::v2d(T a, T b){

	this->x = a;
	this->y = b;
}

template <class T>
v2d<T>::v2d(const v2d<T> & v){
	this->x = v.x;
	this->y = v.y;
}

template <class T>
v2d<T>::~v2d(){
	// put something here
}

template <class T>
v2d<T> & v2d<T>::operator=(const v2d<T> &v){

	this->x = v.x;
	this->y = v.y;
	return *this;
}

template <class T>
v2d<T> & v2d<T>::operator+(const v2d<T> &v){

	x = x + v.x;
	y = y + v.y;
	return *this;
}

template <class T>
double v2d<T>::operator*(const v2d<T> &v){
	double result;
	result = x*v.x + y*v.y;
	return result;

}

template <class T>
v2d<T> & v2d<T>::operator*(double k){

	x = k*x;
	y = k*y;
	return *this;
}

template <class T>
double v2d<T>::length(){

	double l = sqrt(x*x + y*y);
	return l;
}


#endif
