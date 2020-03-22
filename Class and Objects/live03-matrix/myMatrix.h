#ifndef MYMATRIX_H_
#define MYMATRIX_H_

#include <utility>

class myMatrix{

public:

    // Constructor method
    myMatrix(unsigned int rows, unsigned int columns);
    // Destructor method
    ~myMatrix(void);

    // Other useful members
    unsigned int numRows(void);
    unsigned int numColumns(void);
    double & operator[](std::pair<unsigned int, unsigned int>);
    void scalar_mult(double u);
    void transpose(void);
    void display(void);
    // User-defined assignment
    myMatrix & operator=(myMatrix &);

private:
    // Private members
    unsigned int rows;
    unsigned int columns;
    double * m;

};

#endif /* MYMATRIX_H_ */
