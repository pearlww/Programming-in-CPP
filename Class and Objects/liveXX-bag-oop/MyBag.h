#ifndef MYBAG_H_
#define MYBAG_H_

#include "actions.h"
#include <string>
#include <vector>

//using namespace actions;
using namespace std;

class myBag {
public:
    // some constructors
    myBag(int);
    myBag(int,int);
    // a method to "dispatch" actions
    void update(action,string);
    // a simple method to display the myBag.
    void display(void);
    // the methods implementing the "actions"
    void add(int);
    void del(int);
    void sortIt(void);
    void makeSet(void);
    void read(string);
    void flip(void);
    // some extra methods
    bool empty(void);
    int pick(void);

private:
    vector<unsigned int> b;
};

#endif /* MYBAG_H_ */
