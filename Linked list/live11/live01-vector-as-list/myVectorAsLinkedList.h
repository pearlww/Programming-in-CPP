
#ifndef MYVECTORASLINKEDLIST_H_
#define MYVECTORASLINKEDLIST_H_

#include "linked-list.h"

class myVector{

public:

    // Constructor method
    myVector(void);
    // Destructor method
    ~myVector(void);

    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int);

    // User-defined assignment
    myVector & operator=(myVector &);

private:
    // Private members
    // used to implement the class, not meant for the user
    // the myVector is implemented as a linked list
    Node<int> * first;
    // the size is kept updated for efficiency
    unsigned int vsize;

    // some hidden methods
    //void push_backR(int x, Node<int> * & p);
    //Add an element at the end of the myVector
    void push_backR(Node<int> * currentElement, Node<int> * newElement);

    //Get element at a certain position
    int at_iter(unsigned int i);
    int at_rec(Node<int>* currentElement,unsigned int i);

    void erase(void);
    void eraseR(Node<int> * p);

};

#endif /* MYVECTORASLINKEDLIST_H_ */
