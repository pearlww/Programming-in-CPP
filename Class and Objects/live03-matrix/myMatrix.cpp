#include <iostream>
#include "myMatrix.h"
using namespace std;

// constructor method
myMatrix::myMatrix(unsigned int rows2, unsigned int columns2){
    rows = rows2;
    columns = columns2;
    // we implement a myMatrix with an array
    m = new double[rows*columns];

/*
    for(int i=0;i<rows*columns;i++){
    		m[i]=0.0;
    }
*/

    return;
}

// destructor method
myMatrix::~myMatrix(void){
    delete [] m;
    return;
}

unsigned int myMatrix::numRows(void){
    return rows;
}


unsigned int myMatrix::numColumns(void){
    return columns;
}


// method to access elements in the myMatrix
double & myMatrix::operator[](pair<unsigned int, unsigned int> p) {
    if(p.first > rows || p.second > columns ){
        throw std::out_of_range ("you went out of range of your myMatrix!");
    }
    // note that we access the right element
    // this is completely transparent to the user
    return m[(p.first*columns)+p.second];
}

// scalar multiplication method
void myMatrix::scalar_mult(double u){
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=0; j<columns; j++){
            m[(i*columns)+j] = m[(i*columns)+j] * u;
        }
    }
}

// myMatrix trasposition method
void myMatrix::transpose(void){

    // we first traspose the values
    double aux;
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=i; j<columns; j++){
            aux = m[(i*columns)+j];
            m[(i*columns)+j] = m[(j*rows)+i];
            m[(j*rows)+i] = aux;
        }
    }

    // and now we change the myMatrix properties
    unsigned int x;
    x = columns;
    columns = rows;
    rows = x;

}

void myMatrix::display(){
    cout.setf(ios::fixed);
    cout.precision(2);
    for(unsigned int i=0; i<rows; i++){
        for(unsigned int j=0; j<columns; j++){
            cout <<(*this)[make_pair(i,j)] << " ";
        }
        cout << endl;
    }
}

// A user defined assignment operator
myMatrix & myMatrix::operator=(myMatrix & v){
	// This is what the default would do
	    this->rows = v.rows;
	    this->columns = v.columns;
	    //this->m = v.m; // which would just copy the pointer

	    delete [] this->m;
	    // we need instead to create a new copy of the underlying array
	    this->m = new double[v.rows*v.columns];
	    for(unsigned int i=0; i<v.rows*v.columns; i++){
	        this->m[i] = v.m[i];
	    }
	    return * this;
}
