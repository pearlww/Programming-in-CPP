#ifndef MYVECTOR_H_
#define MYVECTOR_H_

class myVector{

public:

    // Constructor method
    myVector(void);
    myVector(int initialCapacity);
    // Destructor method ,because you use "new" to allcate space
    ~myVector(void);

    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int);

    // User-defined assignment
    //myVector & operator=(myVector &);

private:
    // Private members
    // used to implement the class, not meant for the user
    int * content;
    unsigned int vsize;
    unsigned int capacity;
    void resize(void);

};

#endif /* MYVECTOR_H_ */
