#include "MyBag.h"
#include <iostream>
#include <fstream>
#include <stack>

myBag::myBag(int x){
    vector<unsigned int> a(x);
    b = a;
    return;
}

myBag::myBag(int x, int y){
    vector<unsigned int> a(x,y);
    b = a;
    return;
}

void myBag::add(int x){
    // Insert at the beginning
    b.insert(b.begin(),x);
    // Insert at the end (more efficient)
    //b.push_back(x);
    return;
}

void myBag::del(int x){
    for(vector<unsigned int>::iterator i=b.begin(); i!=b.end(); i++){
        if(*i==x){
            b.erase(i);
            return;
        }
    }
    return;
}

void myBag::sortIt(void){
    // sort a vector between to positions
    sort(b.begin(),b.end());
    return;
}

void myBag::makeSet(void){
    sort(b.begin(),b.end());
    for(vector<unsigned int>::iterator i=b.begin(); i!=b.end(); i++){
        while(i+1!=b.end() && *i==*(i+1)){
            b.erase(i+1);
        }
    }
    return;
}

void myBag::read(string s){
    ifstream f;
    string n;

    // open file s into the filestream f
    f.open(s);
    // check if the file exists
    if(f.fail()) return;
    // while we can read "words"...
    while(f >> n) {
        update(actions::add,n);
    }
    f.close();
    return;
}

void myBag::flip(void){
    stack<unsigned int> my_pile;
    // dump the myBag into the stack
    while(!b.empty()){
        my_pile.push(b[0]);
        b.erase(b.begin());
    }
    // dump the stack into the myBag again
    while(!my_pile.empty()){
        b.push_back(my_pile.top());
        my_pile.pop();
    }
    return;
}

int myBag::pick(){
    int x;

    x = b[b.size()-1];
    b.erase(b.end()-1);
    return x;
}

bool myBag::empty(){
    return b.empty();
}


// function to print the content of the myBag
void myBag::display(){
    cout << "The myBag is : ";
    // this is a simple example of how to use an iterator
    // to go through all the elements in a vector
    for(vector<unsigned int>::iterator i=b.begin(); i!=b.end(); i++){
        // the iterator is used like a pointer
        // *i is used to de-reference the iterator/pointer
        cout << *i << " ";
    }
    cout << endl;
    return;
}

// this function deals with actions on a myBag
void myBag::update(action a, string s){
    string n;

    switch(a){

        case actions::add:
            add(stoi(s));
            break;

        case actions::del:
            del(stoi(s));
            break;

        case actions::sortIt:
            sortIt();
            break;

        case actions::makeSet:
            makeSet();
            break;

        case actions::read:
            read(s);
            break;

        case actions::flip:
            flip();
            break;

        case actions::none:
            break;

        default:
            break;

    }
    return;
}
