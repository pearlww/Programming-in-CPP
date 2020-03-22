//============================================================================
// Name        : live03-find.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Library "algorithm" provides a function that can be used
// 				 to find elements in vectors
// 				 http://en.cppreference.com/w/cpp/algorithm/find
//
// 				 We try here to implement a similar function to
// 				 search in an (ordered) vector
// 				 we provide zthree possible solutions
//============================================================================

#include<iostream>
#include<vector>

using namespace std;

// Library "algorithm" provides a function that can be used
// to find elements in vectors
// http://en.cppreference.com/w/cpp/algorithm/find

// We try here to implement a similar function to
// search in an (ordered) vector
// we provide three possible solutions

// Simple function to display a vector
template <class C>
void display(vector<C> & v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

// Linear search
template <class C>
bool find_linear(vector<C> & v, C e){
    // We just scan all the elements
    for(int i = 0; i < v.size(); i++){
        if(v[i]==e) return true;
    }
    return false;
}

// Binary search - iterative
template <class C>
bool find_binary_iterative(vector<C> & v, C e){
    int start = 0;
    int end = int(v.size())-1;
    int middle;

    do {
        middle = start+((end-start)/2);
        // Check element in the middle
        if(v[middle] == e) return true;
        if(e < v[middle]){
            // Search in the left part
            end = middle-1;
        }
        else {
            // Search in the right part
            start = middle+1;
        }
    } while (start<=end);

    return false;
}

// Binary search - recursive
template <class C>
bool find_binary_recursive(vector<C> & v, C e){

    // Check if vector is empty
    if (v.size() == 0) return false;

    // Check element in the middle
    int middle = (int(v.size())-1)/2;
    if (v[middle] == e) return true;

    // Check if there is something left
    if(v.size() <= 1) return false;

    if (v[middle]>e) {
        // Search in the left part  // how can w be constructed? 
        vector<C> w(v.begin(), v.begin()+(middle));
        return find_binary_recursive(w,e);
    } else {
        // Search in the right part
        vector<C> w(v.begin()+(middle+1), v.end());
        return find_binary_recursive(w,e);
    }

}

// Binary search - recursive
// In this version we do not create new copies of the vector
template <class C>
bool find_binary_recursive2(vector<C> & v, C e);

template <class C>
bool find_binary_recursive2_rec(vector<C> & v, C e, int start, int end){

    // Check if sub-vector is empty
    if (start > end) return false;

    // Check if middle element
    int middle = start+((end-start)/2);
    if (v[middle] == e) return true;

    // Check if thre is something left
    if(start == end) return false;

    if (v[middle]>e) {
        // Search in the left part
        return find_binary_recursive2_rec(v,e,start,middle-1);
    } else {
        // Search in the right part
        return find_binary_recursive2_rec(v,e,middle+1,end);
    }

}

template <class C>
bool find_binary_recursive2(vector<C> & v, C e){
    return find_binary_recursive2_rec(v,e,0,v.size()-1);
}

int main(void){
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(11);
    v.push_back(13);

    cout << "The vector is: " ;
    display(v);
    cout << "2 in v? " << (find_linear(v,2)?"YES":"NO") << endl;
    cout << "2 in v? " << (find_binary_iterative(v,2)?"YES":"NO") << endl;
    cout << "2 in v? " << (find_binary_recursive(v,2)?"YES":"NO") << endl;
    cout << "2 in v? " << (find_binary_recursive2(v,2)?"YES":"NO") << endl;

    cout << "11 in v? " << (find_linear(v,11)?"YES":"NO") << endl;
    cout << "11 in v? " << (find_binary_iterative(v,11)?"YES":"NO") << endl;
    cout << "11 in v? " << (find_binary_recursive(v,11)?"YES":"NO") << endl;
    cout << "11 in v? " << (find_binary_recursive2(v,11)?"YES":"NO") << endl;

    return 0;
}
